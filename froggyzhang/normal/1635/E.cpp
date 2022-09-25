#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,T[N],x[N],y[N],d[N],g[N],col[N];
vector<int> G[N];
bool dfs(int u){
	for(auto v:G[u]){
		if(~col[v]){
			if(col[u]==col[v])return false;
		}
		else{
			col[v]=col[u]^1;
			if(!dfs(v))return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>T[i]>>x[i]>>y[i];
		G[x[i]].push_back(y[i]);
		G[y[i]].push_back(x[i]);
	}
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;++i){
		if(!~col[i]){
			col[i]=0;
			if(!dfs(i)){
				cout<<"NO\n";
				return 0;
			}
		}
	}
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	queue<int> q;
	for(int i=1;i<=m;++i){
		if(T[i]!=col[x[i]]+1){
			swap(x[i],y[i]);
		}
		G[x[i]].push_back(y[i]);
		++d[y[i]];
	}
	for(int i=1;i<=n;++i){
		if(!d[i])q.push(i);
	}
	int cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		g[u]=1e9-(cnt++);
		for(auto v:G[u]){
			if(!--d[v])q.push(v);
		}
	}
	if(cnt!=n){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;++i){
		cout<<(col[i]?'L':'R')<<' '<<g[i]<<'\n';
	}
	return 0;
}