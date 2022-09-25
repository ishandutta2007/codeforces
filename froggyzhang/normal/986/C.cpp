#include<bits/stdc++.h>
using namespace std;
#define N 22
typedef long long ll;
int n,m,a[1<<N],all;
bool vis[1<<N],c[1<<N];
void dfs(int u){
	if(vis[u])return;
	vis[u]=1;
	if(c[u]){
		dfs(u^all);
	}
	for(int i=0;i<n;++i){
		if(u>>i&1)dfs(u^(1<<i));
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;all=(1<<n)-1;
	for(int i=0;i<m;++i){
		cin>>a[i];
		c[a[i]]=1;
	}
	int ans=0;
	for(int i=0;i<m;++i){
		if(!vis[a[i]])++ans,dfs(a[i]^all);
	}
	cout<<ans<<'\n';
	return 0;
}