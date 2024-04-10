#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
vector<int> G[N];
int n,d[N],jb[N],ans;
void dfs(int u,int fa){
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);	
		d[u]+=!jb[v];
	}
	ans+=!d[u];
	if(fa&&d[u]){
		bool ok=true;
		for(auto v:G[u]){
			if(v==fa)continue;
			if(!d[v])ok&=!d[v];	
		}
		ans-=ok;
		jb[u]=ok;
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		G[i].clear();
		jb[i]=d[i]=0;
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans=0;
	dfs(1,0);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}