#include<bits/stdc++.h>
using namespace std;
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+1;
int n,ans,f[N],g[N];
vector<int>e[N];
V add_edge(int x,int y){e[x].push_back(y),e[y].push_back(x);}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V dfs(int u,int fa=0){
	int d=e[u].size();
	for(int v:e[u])if(v!=fa){
		dfs(v,u);
		cmax(ans,max(f[u]+g[v]+1,g[u]+f[v]+d-2));
		cmax(f[u],g[v]),cmax(g[u],f[v]);
	}
	cmax(ans,++f[u]),cmax(ans,g[u]+=d-1-!!fa),cmax(f[u],g[u]);
}
int main(){
	scanf("%d",&n);
	for(int x,y;--n;add_edge(x,y))scanf("%d%d",&x,&y);
	dfs(1),cout<<ans;
	return 0;
}