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

typedef long long ll;

const int MAXN = 40;
const int HALF = 20;

int n,m;
int col[MAXN];

ll f[1 << HALF];

bool vis[MAXN];
bool G[MAXN][MAXN];

void FWT(ll *v,int N)
{
	
}

ll no0()
{
	int N1 = n / 2,N2 = n - N1;
	ll res = 0;
	for (int i = 0;i < (1 << N1);i++)
	{
		f[i] = 1;
		for (int j = 0;f[i] && j < N1;j++)
			for (int k = 0;f[i] && k < N1;k++)
				if (G[j][k] && (i >> j & 1) && (i >> k & 1))
					f[i] = 0;
	}
	for (int i = 1;i < (1 << N1);i <<= 1)
		for (int j = 0;j < (1 << N1);j += (i << 1))
			for (int k = 0;k < i;k++)
				f[j + k + i] += f[j + k];
	for (int i = 0;i < (1 << N2);i++)
	{
		bool ok = 1;
		for (int j = 0;ok && j < N1;j++)
			for (int k = 0;ok && k < N1;k++)
				if (G[j + N1][k + N1] && (i >> j & 1) && (i >> k & 1))
					ok = 0;
		if (!ok)
			continue;
		int mask = 0;
		for (int j = 0;j < N2;j++)
			if (i >> j & 1)
				for (int k = 0;k < N1;k++)
					if (G[j + N1][k])
						mask |= 1 << k;
		res += f[mask ^ ((1 << N1) - 1)];
	}
	return res;
}

void dfs(int u)
{
	if (vis[u])
		return;
	vis[u] = 1;
	for (int i = 0;i < n;i++)
		if (G[u][i])
			dfs(i);
}

ll no1()
{
	int cnt = 0;
	for (int i = 0;i < n;i++)
		if (!vis[i])
		{
			cnt++;
			dfs(i);
		}
	return 1ll << cnt;
}

ll no01()
{
	int cnt = 0;
	for (int i = 0;i < n;i++)
	{
		bool none = 1;
		for (int j = 0;none && j < n;j++)
			if (G[i][j])
				none = 0;
		cnt += none;
	}
	return 1ll << cnt;
}

bool fill(int u,int c)
{
	if (~col[u])
		return col[u] == c;
	if (col[u] == -1)
		col[u] = c;
	for (int i = 0;i < n;i++)
		if (G[u][i] && !fill(i,c ^ 1))
			return 0;
	return 1;
}

ll no02()
{
	memset(col,-1,sizeof(col));
	int cnt = 0;
	for (int i = 0;i < n;i++)
		if (col[i] == -1)
		{
			if (!fill(i,0))
				return 0;
			cnt++;
		}
	return 1ll << cnt;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		u--,v--;
		G[u][v] = G[v][u] = 1;
	}
	printf("%lld\n",(bool)m * (1ll << n) - 2 * no0() - no1() + 2 * no01() + no02());
	return 0;
}