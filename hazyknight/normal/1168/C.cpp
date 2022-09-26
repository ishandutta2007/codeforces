#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 300005;

int n,q,u,v;
int a[MAXN];
int first[20];
int nxt[MAXN][20];

int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	a[n + 1] = (1 << 20) - 1;
	for (int i = 0;i < 20;i++)
	{
		first[i] = n + 1;
		nxt[n + 1][i] = n + 1;
	}
	for (int i = n;i >= 1;i--)
	{
		for (int j = 0;j < 20;j++)
			nxt[i][j] = n + 1;
		for (int j = 0;j < 20;j++)
			if (a[i] >> j & 1)
			{
				nxt[i][j] = i;
				for (int k = 0;k < 20;k++)
					nxt[i][k] = min(nxt[i][k],nxt[first[j]][k]);
				first[j] = i;
			}
	}
	while (q--)
	{
		scanf("%d%d",&u,&v);
		bool ok = 0;
		for (int i = 0;i < 20;i++)
			if ((a[v] >> i & 1) && nxt[u][i] <= v)
			{
				ok = 1;
				break;
			}
		puts(ok ? "Shi" : "Fou");
	}
	return 0;
}