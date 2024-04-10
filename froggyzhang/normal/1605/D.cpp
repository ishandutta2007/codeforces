#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,dep[N],ans[N],vis[N];
vector<int> A,B,G[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	dep[u]&1?A.push_back(u):B.push_back(u);
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);	
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)G[i].clear(),vis[i]=0;
	for(int i=1;i<n;++i){
		int u,v;	
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	A.clear(),B.clear();
	dfs(1,0);
	if(A.size()>B.size())swap(A,B);
	int t=1;
	while((t<<1)<=n)t<<=1;
	while(t){
		if(A.size()>=t-(t>>1)){
			for(int i=t>>1;i<t;++i){
				ans[A.back()]=i;A.pop_back();vis[i]=1;
			}
		}
		t>>=1;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i])ans[B.back()]=i,B.pop_back();
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}