#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repeq(i,a,b) for(int i=a;i<=b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
const int sz=2e5, infty=1<<30;
int n, par[sz], col[sz], k;
vector<vector<int> > g;
void dfs(int u)
{
	if(col[u]>k)
		k=col[u];
	int j=1;
	for(int v:g[u])
		if(par[v]<0)
		{
			par[v] = u;
			while(j==col[u]||j==col[par[u]])
				++j;
			col[v]=j;
			++j;
			dfs(v);
		}
}
int main()
{
	scanf("%d",&n);
	g.resize(n);
	rep(i,0,n-1)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	par[0]=0;
	rep(i,1,n)
		par[i]=-1;
	col[0]=1;
	k=0;
	dfs(0);
	cout<<k<<endl;
	rep(i,0,n)
		printf("%d ",col[i]);
	printf("\n");
}