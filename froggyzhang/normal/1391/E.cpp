#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 500050
inline int read(){
	int x=0,f=1;
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
int T,n,m,dep[N],f[N],vis[N];
vector<int> G[N],p[N];
void dfs(int u,int fa){
	f[u]=fa;
	dep[u]=dep[fa]+1;
	p[dep[u]].push_back(u);
	vis[u]=1;
	for(auto v:G[u]){
		if(vis[v])continue;
		dfs(v,u);
	}
}
void Solve(){
	for(int i=1;i<=n;++i){
		G[i].clear();
		p[i].clear();
		vis[i]=0;
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for(int u=1;u<=n;++u){
		if(dep[u]>=((n+1)>>1)){
			printf("PATH\n%d\n",dep[u]);
			while(u){
				printf("%d ",u);
				u=f[u];
			}
			printf("\n");
			return; 
		}
	}
	vector<int> ans;
	for(int i=1;i<n;++i){
		if((int)p[i].size()&1)p[i].pop_back();
		for(auto u:p[i]){
			ans.push_back(u);
		}
	}
	printf("PAIRING\n");
	printf("%d\n",(int)ans.size()>>1);
	for(int i=0;i<(int)ans.size();i+=2){
		printf("%d %d\n",ans[i],ans[i+1]);
	}
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		Solve();
	}
	return 0;
}