#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int ask(int u)
{
	printf("? %d\n",u);
	fflush(stdout);
	int v;
	scanf("%d",&v);
	return v;
}

int deg[MAXN], vis[MAXN], fa[MAXN];
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&deg[i]);
	
	static pii p[MAXN];
	for(int i=1; i<=n; ++i)
		p[i] = {deg[i], i};
	sort(p+1, p+n+1);
	
	for(int i=1; i<=n; ++i)
		fa[i] = i, vis[i] = 0;
	for(int it=n; it>=1; --it)
	{
		int u = p[it].second;
		if(vis[u]) continue;
		
		vis[u] = 1;
		for(int i=1; i<=deg[u]; ++i)
		{
			int v = ask(u);
			fa[find(u)] = find(v);
			if(vis[v]) break;
			vis[v] = 1;
		}
	}
	
	printf("! ");
	for(int i=1; i<=n; ++i)
		printf("%d ",find(i));
	printf("\n");
	fflush(stdout);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}