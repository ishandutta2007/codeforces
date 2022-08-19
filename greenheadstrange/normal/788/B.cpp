#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long
using namespace std;
int n, m;
ll ds[maxn];
ll ans = 0;
ll self = 0;
int fa[maxn], size[maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) fa[i] = i; 
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		fa[gfa(u)] = gfa(v);
		size[gfa(u)]++;
		if(u == v) self++;
		else ds[u]++, ds[v]++;
	}
	int ns = 0;
	for(int i = 1; i <= n; i++)
		if(fa[i] == i && size[i]) 
			ns++;
	if(ns >= 2)
	{
		printf("0\n");
		return 0;
	}
	ll ans = self * (ll)(m - self);
	ans += self * (self - 1) / 2; 
	for(int i = 1; i <= n; i++)
		ans += ds[i] * (ds[i] - 1) / 2;
	printf("%I64d\n", ans);
	return 0;
}