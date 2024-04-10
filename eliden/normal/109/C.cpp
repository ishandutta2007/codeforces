#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
const int sz=1e5;
typedef long long ll;
int n;
vector<vector<int> > g;
bool vis[sz];
int dfs(int u)
{
	vis[u] = true;
	int x=1;
	for(int v:g[u])
		if(!vis[v])
			x+=dfs(v);
	return x;
}
int main()
{
	scanf("%d",&n);
	g.resize(n);
	rep(i,0,n-1)
	{
		int u, v, w;
		scanf("%d%d%d",&u,&v,&w);
		--u, --v;
		bool lucky=true;
		while(w>0 && lucky)
		{
			int r = w%10;
			if(r!=4 && r!=7)
				lucky = false;
			w/=10;
		}
		if(!lucky)
		{
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	ll tot=0;
	rep(i,0,n)
		vis[i]=false;
	rep(i,0,n)
		if(!vis[i])
		{
		    ll x = dfs(i);
			tot+=x*(n-x)*(n-x-1);
		}
	cout<<tot<<endl;
}