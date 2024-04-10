#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int row[55][55], col[55][55];
char s[55][55];

int allBlack(int i, int j, int ii, int jj)
{
	return i == ii ? row[i][jj] == row[i][j - 1] : col[i - 1][j] == col[ii][j];
}

int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) 
	{
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= n; j++) 
		{
			row[i][j] = row[i][j - 1] + (s[i][j] == 'W');
			col[i][j] = col[i - 1][j] + (s[i][j] == 'W');
		}
	}
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
				for (int ii = 1; ii <= m; ii++)
					for (int jj = 1; jj <= n; jj++)
						if (s[i][j] == 'B' && s[ii][jj] == 'B')
						{
							if (allBlack(i, j, i, jj) && allBlack(i, jj, ii, jj)) continue;
							if (allBlack(i, j, ii, j) && allBlack(ii, j, ii, jj)) continue;
							puts("NO");
							return 0; 
						}
			
	puts("YES");
}