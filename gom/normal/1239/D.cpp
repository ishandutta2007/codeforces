#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef vector<vector<ll>> mat;
const ll mod=1e6;
const int N=1e6+5;
int t,n,m,scc[N],vis[N],deg[N],ansScc,cur,curScc,v1,v2;
deque<int> dq;
vector<int> g[N];
int dfs(int v)
{
	dq.push_back(v);
	vis[v]=++cur;
	int res=vis[v];
	for(auto &it : g[v]){
		if(!vis[it]) res=min(res,dfs(it));
		else if(!scc[it]) res=min(res,vis[it]);
	}
	if(res==vis[v]){
		curScc++;
		while(dq.size()){
			int u=dq.back(); dq.pop_back();
			scc[u]=curScc;
			if(u==v) break;
		}
	}
	return res;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++) vis[i]=scc[i]=deg[i]=0;
	cur=curScc=v1=v2=ansScc=0;
	for(int u,v,i=1;i<=m;i++){
		cin>>u>>v;
		if(u!=v) g[u].push_back(v);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	if(curScc==1){
		cout<<"No\n";
		return;
	}
	for(int i=1;i<=n;i++) for(auto &it : g[i]) if(scc[i]!=scc[it]) deg[scc[i]]++;
	for(int i=1;i<=curScc;i++) if(!deg[i]) ansScc=i;
	for(int i=1;i<=n;i++) if(scc[i]==ansScc) v1++;
	v2=n-v1;
	cout<<"Yes\n"<<v1<<" "<<v2<<"\n";
	for(int i=1;i<=n;i++) if(scc[i]==ansScc) cout<<i<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++) if(scc[i]!=ansScc) cout<<i<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>t;
	while(t--) solve();
	return 0;
}