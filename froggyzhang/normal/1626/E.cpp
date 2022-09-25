#include<bits/stdc++.h>
using namespace std;
#define N 300010
typedef long long ll;
int n,c[N],siz[N],tot,ans[N];
vector<int> G[N],H[N];
void dfs(int u,int fa){
	siz[u]=c[u];
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		if(siz[v]>=2)H[v].push_back(u);
		if(tot-siz[v]>=2)H[u].push_back(v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		tot+=c[i];
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(c[i]){
			for(auto v:G[i]){
				H[i].push_back(v);	
			}
			q.push(i);
			ans[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:H[u]){
			if(!ans[v]){
				ans[v]=1,q.push(v);
			}	
		}
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}