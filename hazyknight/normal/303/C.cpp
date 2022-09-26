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

const int MAXN = 5005;
const int MAXV = 1000005;

int n,K,id,ANS;
int a[MAXN];
int match[MAXN];
int fa[MAXN];
int vis[MAXN];
int tot[MAXV];

bool valid[MAXV];

pair<int,int> e[MAXV][12];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int main()
{
	scanf("%d%d",&n,&K);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			if (tot[a[j] - a[i]] <= 10)
				e[a[j] - a[i]][++tot[a[j] - a[i]]] = make_pair(i,j);
	ANS = 1000001;
	int tp = 0;
	for (int i = 1000000;i >= n - K;i--)
	{
		bool ok = 1;
		int cnt = 0;
		for (int j = i;j <= 1000000;j += i)
		{
			cnt += tot[j];
			if (j > i && !valid[j])
				ok = 0;
		}
		if (cnt > (K + 1) * K / 2 || !ok)
			continue;
		id = 0;
		int ans = 0;
		for (int j = i;j <= 1000000 && ans <= K;j += i)
			for (int k = 1;k <= tot[j] && ans <= K;k++)
			{
				int u = e[j][k].first,v = e[j][k].second;
				if (vis[u] != i)
				{
				    vis[u] = i;
					match[u] = ++id;
					fa[id] = id;
				}
				if (vis[v] != i)
				{
				    vis[v] = i;
					match[v] = ++id;
					fa[id] = id;
				}
				u = match[u];
				v = match[v];
				if (getroot(u) != getroot(v))
				{
					ans++;
					fa[getroot(u)] = getroot(v);
				}
			}
		if (ans <= K)
		{
			ANS = i;
			valid[i] = 1;
		}
	}
	printf("%d\n",ANS);
	return 0;
}