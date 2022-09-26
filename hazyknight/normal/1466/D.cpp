#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int T,n;
int w[MAXN];
int deg[MAXN];
int p[MAXN];

ll ans;

bool cmp(const int &a,const int &b)
{
	return w[a] > w[b];
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			deg[i] = 0;
		ans = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&w[i]);
			ans += w[i];
		}
		for (int u,v,i = 1;i < n;i++)
		{
			scanf("%d%d",&u,&v);
			deg[u]++;
			deg[v]++;
		}
		for (int i = 1;i <= n;i++)
			p[i] = i;
		sort(p + 1,p + n + 1,cmp);
		printf("%lld ",ans);
		for (int i = 2,j = 1;i < n;i++)
		{
			while (deg[p[j]] == 1)
				j++;
			ans += w[p[j]];
			deg[p[j]]--;
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}