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

const int MAXN = 200005;
const int MAXM = 125;

int n,m,N;
int bel[MAXN];
int a[MAXN];
int Fa[MAXM];
int tmp[MAXM << 1];
int G[MAXM][MAXM];
int fa[MAXM][MAXM];
int lst[MAXN][MAXM];

ll ans;

string s;
string p[MAXM];

map<string,int> match;

bool mark[6];

int getroot(int *fa,int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa,fa[u]);
}

void dfs(int d)
{
	if (d > m)
	{
		p[match[s] = ++N] = s;
		return;
	}
	for (int i = 1;i <= m;i++)
		if (!mark[i])
		{
			mark[i] = 1;
			s += char(i + '0');
			dfs(d + 1);
			s.erase(s.begin() + s.size() - 1);
			mark[i] = 0;
		}
}

void init()
{
	dfs(1);
	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= N;j++)
		{
			int a[m + 1] = {0},b[m + 1] = {0};
			for (int k = 1;k <= m;k++)
			{
				a[k] = p[i][k - 1] - '0';
				b[k] = p[j][k - 1] - '0';
			}
			for (int k = 1;k <= m;k++)
				b[k] = a[b[k]];
				s.clear();
			for (int k = 1;k <= m;k++)
				s += char(b[k] + '0');
			G[i][j] = match[s];
		}
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
			fa[i][j] = j;
		for (int u = 1;u <= N;u++)
		{
			int v = G[u][i];
			if (getroot(fa[i],u) != getroot(fa[i],v))
				fa[i][getroot(fa[i],u)] = getroot(fa[i],v);
		}
	}
}

void merge(int *A,int *B)
{
	for (int i = 1;i <= N;i++)
		tmp[i] = A[i];
	for (int i = 1;i <= N;i++)
		tmp[i + N] = B[i];
	for (int i = 1;i <= N;i++)
		if (getroot(tmp,i) != getroot(tmp,i + N))
			tmp[getroot(tmp,i + N)] = getroot(tmp,i);
	for (int i = 1;i <= N;i++)
		A[i] = tmp[i];
}

int main()
{
	scanf("%d%d",&n,&m);
	init();
	for (int i = 1;i <= n;i++)
	{
		s.clear();
		for (int v,j = 1;j <= m;j++)
		{
			scanf("%d",&v);
			s += char(v + '0');
		}
		a[i] = match[s];
	}
	for (int i = 1;i <= n;i++)
	{
		memcpy(lst[i],lst[i - 1],sizeof(lst[i - 1]));
		lst[i][a[i]] = i;
	}
	for (int i = 1;i <= n;i++)
	{
		memcpy(Fa,fa[a[i]],sizeof(Fa));
		int cur = i;
		while (cur > 0)
		{
			int pre = 0,cnt = 0;
			for (int j = 1;j <= N;j++)
			{
				if (getroot(Fa,1) != getroot(Fa,j))
					pre = max(pre,lst[cur][j]);
				else
					cnt++;
			}
			ans += (cur - pre) * cnt;
			merge(Fa,fa[a[pre]]);
			cur = pre;
		}
	}
	printf("%lld\n",ans);
	return 0;
}