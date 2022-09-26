#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int T,n,m;

char s[MAXN][MAXN];

bool vis[MAXN][MAXN];
bool chk[MAXN][MAXN];

void findpath(int r,int c)
{
	for (int i = r - 1;i >= 1;i--)
	{
		if (s[i][c] == 'X')
			return;
		s[i][c] = 'X';
		if (s[i][c - 1] == 'X' && s[i][c + 1] == 'X')
		{
			vis[i][c + 1] = 0;
			return;
		}
		if (s[i][c - 1] == 'X')
			return;
		if (s[i][c + 1] == 'X')
			return;
	}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 0;i <= n + 1;i++)
			for (int j = 0;j <= m + 1;j++)
				s[i][j] = '.';
		for (int i = 1;i <= n;i++)
			scanf("%s",s[i] + 1);
		for (int i = 1 + (n % 3 == 0);i <= n;i += 3)
			for (int j = 1;j <= m;j++)
				s[i][j] = 'X';
		for (int i = 1 + (n % 3 == 0);i <= n;i += 3)
			if (i + 2 <= n)
			{
				if (s[i + 1][2] == 'X' || s[i + 2][2] == 'X')
					s[i + 1][2] = s[i + 2][2] = 'X';
				else
					s[i + 1][1] = s[i + 2][1] = 'X';
			}
		for (int i = 1;i <= n;i++,putchar('\n'))
			for (int j = 1;j <= m;j++)
				putchar(s[i][j]);
	}
	return 0;
}