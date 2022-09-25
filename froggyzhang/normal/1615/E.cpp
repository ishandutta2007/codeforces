#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,m,son[N],dep[N],mxdep[N],f[N];
ll ans;
vector<int> A;
vector<int> G[N];
void dfs(int u){
	mxdep[u]=dep[u];
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
		if(mxdep[v]>mxdep[son[u]]){
			son[u]=v;
			mxdep[u]=mxdep[v];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	for(int u=1;u<=n;++u){
		if(son[f[u]]^u){
			A.push_back(mxdep[u]-dep[u]);
		}
	}
	sort(A.begin(),A.end(),greater<int>());
	if(m>=A.size()){
		int t=max((int)A.size(),min(n/2,m));
		ans=1LL*t*(n-t);
	}
	else{
		int W=0;
		for(int i=0;i<m;++i)W+=A[i];
		int res=n-W-m;
		ans=2e18;
		for(int i=0;i<=res;++i){
			ans=min(ans,1LL*(W+res-i)*(m-i));
		}
	}
	cout<<ans<<'\n';
	return 0;
}