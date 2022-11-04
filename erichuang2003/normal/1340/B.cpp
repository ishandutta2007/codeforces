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

const int MAXN = 2005;

int n,k;
int to[MAXN][10];

bool f[MAXN][MAXN];

char S[10];
string s[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",S);
		for (int j = 0;j < 10;j++)
		{
			bool ok = 1;
			int cnt = 0;
			for (int k = 0;k < 7;k++)
			{
				if (S[k] == '1' && s[j][k] == '0')
					ok = 0;
				cnt += s[j][k] - S[k];
			}
			if (ok)
				to[i][j] = cnt;
			else
				to[i][j] = -1;
		}
	}
	f[n + 1][0] = 1;
	for (int i = n;i >= 1;i--)
		for (int j = 0;j < 10;j++)
			if (~to[i][j])
				for (int l = to[i][j];l <= k;l++)
					f[i][l] |= f[i + 1][l - to[i][j]];
	if (!f[1][k])
	{
		puts("-1");
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 9;j >= 0;j--)
			if (~to[i][j] && k >= to[i][j] && f[i + 1][k - to[i][j]])
			{
				putchar('0' + j);
				k -= to[i][j];
				break;
			}
	}
	putchar('\n');
	return 0;
}