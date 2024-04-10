#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 1000005;

int n,m;
int fa[MAXN];

ll tot,ans;
ll cnt[MAXN];
ll deg[MAXN];

bool loop[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		fa[i] = i;
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		if (u == v)
		{
			loop[u] = 1;
			tot++;
			continue;
		}
		deg[u]++;
		deg[v]++;
		fa[getroot(u)] = getroot(v);
	}
	for (int i = 1;i <= n;i++)
	{
		cnt[getroot(i)]++;
		if (loop[i])
			cnt[getroot(i)]++;
	}
	for (int i = 1;i <= n;i++)
		if (cnt[i] > 1)
			cnt[0]++;
	if (cnt[0] > 1)
	{
		puts("0");
		return 0;
	}
	for (int i = 1;i <= n;i++)
		ans += deg[i] * tot;
	ans >>= 1;
	for (int i = 1;i <= n;i++)
		ans += deg[i] * (deg[i] - 1) / 2;
	ans += tot * (tot - 1) / 2;
	printf("%I64d\n",ans);
	return 0;
}