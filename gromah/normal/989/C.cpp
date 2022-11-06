#include <cstdio>
#include <algorithm>
using namespace std;

const int Fx[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int a, b, c, d, Ans[51][51];
bool flag;

int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	puts("50 50");
	if (a > b) swap(a, b), flag = 1;
	for (int i = 1; a > 1 && i <= 50; i += 4)
		for (int j = 1; a > 1 && j <= 50; j += 4)
		{
			Ans[i][j] = 0;
			for (int k = 0; k < 8; k ++)
			{
				int x = i + Fx[k][0], y = j + Fx[k][1];
				if (x && y && x <= 50 && y <= 50)
					Ans[x][y] = 1;
			}
			a --, b --;
		}
	for (int i = 50; d; i -= 2)
		for (int j = 50; d && j; j -= 2)
		{
			if (b) Ans[i][j] = 1, b --;
			else if (c) Ans[i][j] = 2, c --;
			else Ans[i][j] = 3, d --;
		}
	if (flag)
		for (int i = 1; i <= 50; i ++)
			for (int j = 1; j <= 50; j ++)
				if (Ans[i][j] <= 1) Ans[i][j] ^= 1;
	for (int i = 1; i <= 50; i ++)
	{
		for (int j = 1; j <= 50; j ++)
			putchar('A' + Ans[i][j]);
		putchar('\n');
	}
	return 0;
}