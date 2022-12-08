#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;
const int SZ = 2e5;
int p[SZ], up[SZ], dwn[SZ];
vector<vector<int> > g1, g2;
int dfs1(int u)
{
	int s = 0;
	for(int v:g1[u])
		if(v!=p[u])
		{
			p[v] = u;
			s+=dfs1(v);
		}
	for(int v:g2[u])
		if(v!=p[u])
		{
			p[v] = u;
			s+=1+dfs1(v);
		}
	up[u] = s;
	return s;
}
void dfs2(int u)
{
	for(int v:g1[u])
		if(v!=p[u])
		{
			dwn[v]=dwn[u]+(up[u]-up[v])+1;
			dfs2(v);
		}
	for(int v:g2[u])
		if(v!=p[u])
		{
			dwn[v]=dwn[u]+(up[u]-(up[v]+1));
			dfs2(v);
		}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	g1.resize(n);
	g2.resize(n);
	rep(i,0,n-1)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		g1[u].emplace_back(v);
		g2[v].emplace_back(u);
	}
	p[0]=0;
	dfs1(0);
	dwn[0]=0;
	dfs2(0);
	int best = n;
	rep(i,0,n)
		if(up[i]+dwn[i]<best)
			best=up[i]+dwn[i];
	cout << best << endl;
	rep(i,0,n)
		if(up[i]+dwn[i]==best)
			cout << i+1 << " ";
	cout<<endl;
}