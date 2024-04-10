#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m;
vector<int> G[N],g[N];
int col[N],vis[N],ans=1;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
void dfs(int u,int f){
	for(int v:g[u]) if(col[v]) vis[col[v]]=1;
	for(int i=1,j=0;j<g[u].size();i++) {
		while(j<g[u].size()&&col[g[u][j]]) j++;
		if(j>=g[u].size()) break;
		if(vis[i]) continue;
		col[g[u][j]]=i;j++;
		ans=max(ans,i);
	}
	for(int v:g[u]) vis[col[v]]=0;
	for(int v:G[u]) if(v!=f) dfs(v,u);
}
int main() {
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		int x=read();
		for(int j=1;j<=x;j++){
			int y=read();
			g[i].push_back(y);
		}
	}
	for(int i=1;i<n;i++) {
		int u=read(),v=read();
		G[u].push_back(v);G[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",ans);
	for(int i=1;i<=m;i++) printf("%d ",max(col[i],1));
	return 0;
}