#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,T,vis[N],dep[N];
bool t[N];
vector<int> G[N],ans;
void dfs(int u,int c){
	vis[u]=1;
	for(auto v:G[u]){
		if(vis[v]&&t[v])c=0;
	}
	t[u]=c;
	if(c){
		ans.push_back(u),t[u]=true;
	}
	for(auto v:G[u]){
		if(!vis[v])dfs(v,c^1);
	}
}		
void Solve(){
	ans.clear();
	n=read(),m=read();
	for(int i=1;i<=n;++i)G[i].clear(),vis[i]=0,t[i]=0;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vis[1]=1;
	dfs(1,1);
	for(int i=1;i<=n;++i){
		if(!vis[i])return (void)printf("No\n");
	}
	printf("Yes\n");
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%d ",x);
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}