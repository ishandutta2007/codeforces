#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
int n,rt;
vector<pair<int,int> > G[N];
vector<tuple<int,int,int> > ans;
int dfs(int u,int fa,int t){
	int x=0,y=0;
	ll tot=0;
	for(auto [v,w]:G[u]){
		if(v==fa)continue;
		tot+=w;
		(x?y:x)=dfs(v,u,w);
	}
	if(u==rt)return 0;
	if(!x){
		x=u;
		ans.emplace_back(x,rt,t);
	}
	else{
		ans.emplace_back(x,rt,(t-tot)/2);
		ans.emplace_back(y,rt,(t-tot)/2);
		ans.emplace_back(x,y,(tot-t)/2);
	}
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	for(int u=1;u<=n;++u){
		if(G[u].size()==2){
			cout<<"NO\n";return 0;
		}
		if(G[u].size()==1){
			rt=u;
		}
	}
	dfs(rt,0,0);
	cout<<"YES\n";	
	cout<<ans.size()<<'\n';
	for(auto [x,y,w]:ans){
		cout<<x<<" "<<y<<" "<<w<<'\n';
	}
	return 0;
}