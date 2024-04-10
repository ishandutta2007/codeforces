#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 500005;
const ll MOD = 1000000007;

int T,n,m,tot;
int fa[MAXN];
int ans[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int main()
{
		scanf("%d%d",&n,&m);
		for (int i = 0;i <= m;i++)
			fa[i] = i;
		for (int k,u,v,i = 1;i <= n;i++)
		{
			scanf("%d",&k);
			if (k == 1)
			{
				scanf("%d",&u);
				v = 0;
			}
			else
				scanf("%d%d",&u,&v);
			int ru = getroot(u),rv = getroot(v);
			if (ru != rv)
			{
				ans[++tot] = i;
				fa[ru] = rv;
			}
		}
		ll pw = 1;
		for (int i = 1;i <= tot;i++)
			(pw *= 2) %= MOD;
		printf("%lld %d\n",pw,tot);
		for (int i = 1;i <= tot;i++)
			printf("%d ",ans[i]);
		printf("\n");
	return 0;
}