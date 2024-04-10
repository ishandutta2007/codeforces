#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n,m,ans;
int fa[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			fa[i] = i;
		ans = m;
		for (int u,v,i = 1;i <= m;i++)
		{
			scanf("%d%d",&u,&v);
			if (u == v)
			{
				ans--;
				continue;
			}
			int ru = getroot(u),rv = getroot(v);
			if (ru == rv)
				ans++;
			else
				fa[ru] = rv;
		}
		printf("%d\n",ans);
	}
	return 0;
}