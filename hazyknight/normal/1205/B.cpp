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
 
const int MAXN = 100005;
 
int n,tot,m,ans;
int f[205][205];
int match[MAXN];
 
ll a[MAXN];
 
pair<int,int> e[MAXN];
set<pair<int,int> > S;
 
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	for (int i = 0;i <= 62;i++)
	{
		int u = 0,v = 0;
		for (int j = 1;j <= n;j++)
			if (a[j] >> i & 1)
			{
				if (!u)
					u = j;
				else if (!v)
					v = j;
				else
				{
					printf("3\n");
					return 0;
				}
			}
		if (u && v)
		{
			if (!match[u])
				match[u] = ++tot;
			if (!match[v])
				match[v] = ++tot;
			u = match[u];
			v = match[v];
			if (u > v)
				swap(u,v);
			if (S.find(make_pair(u,v)) != S.end())
				continue;
			S.insert(make_pair(u,v));
			e[++m] = make_pair(u,v);
		}
	}
	ans = tot + 1;
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= tot;j++)
			for (int k = 1;k <= tot;k++)
				if (j != k)
					f[j][k] = (1 << 30) - 1;
		for (int j = 1;j <= m;j++)
			if (i != j)
				f[e[j].first][e[j].second] = f[e[j].second][e[j].first] = 1;
		for (int l = 1;l <= tot;l++)
			for (int j = 1;j <= tot;j++)
				for (int k = 1;k <= tot;k++)
					f[j][k] = min(f[j][k],f[j][l] + f[l][k]);
		ans = min(ans,f[e[i].first][e[i].second] + 1);
	}
	if (ans > tot)
		puts("-1");
	else
		printf("%d\n",ans);
	return 0;
}