#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1000005;

int n,m;

char S[MAXN];

vector<char> s[MAXN];
vector<int> sum[MAXN];
vector<int> sum2[MAXN];

int getsum(int xa,int ya,int xb,int yb)
{
	if (xa < 1 || ya < 1 || xb > n || yb > m)
		return 1;
	return sum[xb][yb] - sum[xb][ya - 1] - sum[xa - 1][yb] + sum[xa - 1][ya - 1];
}

int getsum2(int xa,int ya,int xb,int yb)
{
	xa = max(xa,1);
	ya = max(ya,1);
	xb = min(xb,n);
	yb = min(yb,m);
	return sum2[xb][yb] - sum2[xb][ya - 1] - sum2[xa - 1][yb] + sum2[xa - 1][ya - 1];
}

bool ok(int v,bool opt)
{
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			int t = !getsum(i - v,j - v,i + v,j + v);
			if (opt)
				putchar(t ? 'X' : '.');
			sum2[i][j] = sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1] + t;
		}
		if (opt)
			putchar('\n');
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (s[i][j] == 'X' && !getsum2(i - v,j - v,i + v,j + v))
				return 0;
	return 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 0;i <= n;i++)
	{
		s[i].resize(m + 2);
		sum[i].resize(m + 2);
		sum2[i].resize(m + 2);
		if (!i)
			continue;
		scanf("%s",S + 1);
		s[i][0] = s[i][m + 1] = '.';
		for (int j = 1;j <= m;j++)
		{
			s[i][j] = S[j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (S[j] == '.');
		}
	}
	int low = 0,high = min(n,m);
	while (low < high)
	{
		int mid = low + high + 1 >> 1;
		if (ok(mid,0))
			low = mid;
		else
			high = mid - 1;
	}
	printf("%d\n",low);
	ok(low,1);
	return 0;
}