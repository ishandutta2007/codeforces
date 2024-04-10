#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,p[N],vis[N],pos[N];
vector<pair<int,int> > a[N];
vector<int> G[N],ans;
void dfs(int u){
	if(vis[u])return;
	vis[u]=1;
	for(auto v:G[u]){
		dfs(v);
	}
	ans.push_back(u);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>p[i];
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		a[u].emplace_back(v,i);
		a[v].emplace_back(u,i);
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vector<int> A;
		for(int u=i;!vis[u];u=p[u]){
			A.push_back(u);
			vis[u]=1;
		}
		for(int j=0;j<(int)A.size();++j){
			pos[A[j]]=j;
		}
		for(auto u:A){
			sort(a[u].begin(),a[u].end(),[&](pair<int,int> x,pair<int,int> y){return (pos[x.first]-pos[u]+A.size())%A.size()<(pos[y.first]-pos[u]+A.size())%A.size();});
			for(int j=0;j<(int)a[u].size()-1;++j){
				G[a[u][j+1].second].push_back(a[u][j].second);
			}
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;++i){
		if(!vis[i]){
			dfs(i);
		}
	}
	for(auto x:ans){
		cout<<x<<' ';
	}
	cout<<'\n';
	return 0;
}