#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

const int MAXN = 105;

struct Back
{
	int i,j,k;
}pre[MAXN][MAXN][MAXN];

int n,m,l;
int nxta[MAXN][26];
int nxtb[MAXN][26];
int nxts[MAXN][26];
int f[MAXN][MAXN][MAXN];

char a[MAXN];
char b[MAXN];
char s[MAXN];

string S;

int main()
{
	scanf("%s%s%s",a + 1,b + 1,s + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);
	l = strlen(s + 1);
	for (int i = 0;i < 26;i++)
	{
		nxta[n + 1][i] = n + 1;
		nxtb[m + 1][i] = m + 1;
	}
	for (int i = n;i >= 1;i--)
	{
		memcpy(nxta[i],nxta[i + 1],sizeof(nxta[i]));
		nxta[i][a[i] - 'A'] = i;
	}
	for (int i = m;i >= 1;i--)
	{
		memcpy(nxtb[i],nxtb[i + 1],sizeof(nxtb[i]));
		nxtb[i][b[i] - 'A'] = i;
	}
	for (int i = 0;i < l;i++)
		for (int c = 0;c < 26;c++)
			for (int j = 1;j <= i + 1;j++)
			{
				bool ok = (s[j] == c + 'A');
				for (int k = 1;ok && k < j;k++)
					if (s[k] != s[i + 1 - j + k])
					{
						ok = 0;
						break;
					}
				if (ok)
					nxts[i][c] = j;
			}
	for (int i = 0;i <= n;i++)
		for (int j = 0;j <= m;j++)
			if (a[i] == b[j])
				for (int k = 0;k < l;k++)
				{
					for (int c = 0;c < 26;c++)
					{
						int u = nxta[i + 1][c],v = nxtb[j + 1][c],w = nxts[k][c];
						if (u < n + 1 && v < m + 1 && w < l && f[u][v][w] < f[i][j][k] + 1)
						{
							pre[u][v][w] = (Back){i,j,k};
							f[u][v][w] = f[i][j][k] + 1;
						}
					}
				}
	int ans = 0;
	Back cur = (Back){0,0,0};
	for (int i = 0;i <= n;i++)
		for (int j = 0;j <= m;j++)
			for (int k = 0;k < l;k++)
				if (ans < f[i][j][k])
				{
					ans = f[i][j][k];
					cur = (Back){i,j,k};
				}
	while (cur.i)
	{
		S += a[cur.i];
		cur = pre[cur.i][cur.j][cur.k];
	}
	reverse(S.begin(),S.end());
	if (!S.size())
		puts("0");
	else
		puts(S.c_str());
	return 0;
}