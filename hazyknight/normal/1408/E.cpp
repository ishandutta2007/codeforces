#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

struct Edge
{
	int u,v,w;
	
	bool operator < (const Edge &p)const
	{
		return w > p.w;
	}
}e[MAXN];

int T,n,m,tot;
int a[MAXN];
int b[MAXN];
int fa[MAXN];

ll ans;

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int main()
{
	scanf("%d%d",&m,&n);
	for (int i = 1;i <= m;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
		scanf("%d",&b[i]);
	for (int s,i = 1;i <= m;i++)
	{
		scanf("%d",&s);
		for (int x,j = 1;j <= s;j++)
		{
			scanf("%d",&x);
			tot++;
			e[tot].u = i;
			e[tot].v = m + x;
			e[tot].w = a[i] + b[x];
			ans += a[i] + b[x];
		}
	}
	sort(e + 1,e + tot + 1);
	for (int i = 1;i <= n + m;i++)
		fa[i] = i;
	for (int i = 1;i <= tot;i++)
	{
		int ru = getroot(e[i].u),rv = getroot(e[i].v);
		if (ru != rv)
		{
			ans -= e[i].w;
			fa[ru] = rv;
		}
	}
	printf("%lld\n",ans);
	return 0;
}