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
 
const int MAXN = 500005;
 
int T,n,m,a,b;
int u[MAXN];
int v[MAXN];
int fa[MAXN];
int sz[MAXN];
 
bool mark[MAXN];

pair<int,int> tg[MAXN];
map<pair<int,int>,int> S;
 
int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}
 
ll solve()
{
	for (int i = 1;i <= n;i++)
		fa[i] = i,sz[i] = 1;
	for (int i = 1;i <= m;i++)
		if (!mark[u[i]] && !mark[v[i]] && getroot(u[i]) != getroot(v[i]))
		{
			sz[getroot(u[i])] += sz[getroot(v[i])];
			fa[getroot(v[i])] = getroot(u[i]);
		}
	ll res = 0;
	for (int i = 1;i <= n;i++)
		if (!mark[i] && i != a && i != b)
			res += sz[getroot(i)] - 1 - (getroot(a) == getroot(i)) - (getroot(b) == getroot(i));
	return res / 2;
}
 
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for (int i = 1;i <= m;i++)
			scanf("%d%d",&u[i],&v[i]);
		mark[a] = 1;
		ll A = solve();
		for (int i = 1;i <= n;i++)
			tg[i].first = getroot(i);
		mark[a] = 0;
		mark[b] = 1;
		ll B = solve();
		for (int i = 1;i <= n;i++)
			tg[i].second = getroot(i);
		mark[b] = 0;
		S.clear();
		for (int i = 1;i <= n;i++)
			if (i != a && i != b)
				S[tg[i]]++;
		ll C = 0;
		for (map<pair<int,int>,int>::iterator it = S.begin();it != S.end();it++)
			C += (ll)it->second * (it->second - 1) / 2;
		printf("%lld\n",(ll)n * (n - 1) / 2 - (n - 1) * 2 + 1 - A - B + C);
	}
	return 0;
}