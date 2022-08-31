#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define ll long long
using namespace std;
struct eg
{
	int a, b, w;
	bool operator < (const eg &a)const
	{
		return w < a.w;
	}
}p[maxn];
int fa[maxn], size[maxn];
ll ans = 0;
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int main()
{
	int n, m;
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; i++)
		fa[i] = i, size[i] = 1;
	for(int i = 1; i <= n; i++)
		scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].w);
	sort(p + 1, p + 1 + n);
	for(int i = n; i >= 1; i--)
	{
		int afa = gfa(p[i].a), bfa = gfa(p[i].b);
		if(afa == bfa)
		{
			if(size[afa])
				size[afa]--, ans += p[i].w;
		}
		else
		{
			if(size[afa] || size[bfa])
			{
				if(size[bfa]) swap(afa, bfa);
				ans += p[i].w;
				size[afa]--, fa[bfa] = afa, size[afa] += size[bfa];
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}