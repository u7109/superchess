#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int qi[4][4] = { 0 };
int x = 1, y = 1;
bool who = 0;

bool if_win(int w)
{
	//横
	int max_n = 0, max_t = 0;
	for (int i = x - 3; i <= x + 3; i++)
	{
		if (qi[y][i] == w) max_t++;
		else
		{
			if (max_t > max_n) max_n = max_t;
			max_t = 0;
		}
	}
	if (max_n >= 3) return true;

	//列
	max_n = 0, max_t = 0;
	for (int i = y - 3; i <= y + 3; i++)
	{
		if (qi[i][x] == w) max_t++;
		else
		{
			if (max_t > max_n) max_n = max_t;
			max_t = 0;
		}
	}
	if (max_n >= 3) return true;

	//左斜
	max_n = 0, max_t = 0;
	for (int i = -2; i <= 2; i++)
	{
		if (qi[y + i][x + i] == w) max_t++;
		else
		{
			if (max_t > max_n) max_n = max_t;
			max_t = 0;
		}
	}
	if (max_n >= 3) return true;

	//右斜
	max_n = 0, max_t = 0;
	for (int i = -2; i <= 2; i++)
	{
		if (qi[y + i][x - i] == w) max_t++;
		else
		{
			if (max_t > max_n) max_n = max_t;
			max_t = 0;
		}
	}
	if (max_n >= 3) return true;

	return false;
}

void print_qi()
{
	cout << "     1   2   3" << endl;
	cout << "   |---|---|---|" << endl;
	for (int i = 1; i <= 3; i++)
	{
		if (i < 10) cout << i << "  ";
		else cout << i << " ";
		for (int j = 1; j <= 3; j++)
		{
			if (i == y && j == x) cout << "| " << who + 1 << " ";
			else if (qi[i][j] == 0) cout << "|   ";
			else if (qi[i][j] == 1) cout << "| o ";
			else if (qi[i][j] == 2) cout << "| x ";
		}
		cout << "|" << endl;
		cout << "   |---|---|---|" << endl;
	}
}

int main()
{
	char c;
	while (true)
	{
		system("cls");
		print_qi();
		c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 72 && y - 1 > 0) y--;	//上 
			if (c == 80 && y + 1 < 4) y++;	//下 
			if (c == 75 && x - 1 > 0) x--;	//左 
			if (c == 77 && x + 1 < 4) x++;	//右 
		}
		else if (c == 13)
		{
			if (qi[y][x] == 0)
			{
				qi[y][x] = who + 1;
				if (if_win(who + 1))
				{
					cout << who + 1 << " 号玩家赢了";
					break;
				}
				who = !who;
			}
			else
			{
				cout << "这里已经有棋子了" << endl;
			}
		}
	}
	getchar();
	return 0;
}