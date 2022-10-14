#include<bits/stdc++.h>
using namespace std;
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+1;
int T,n,rt,ans;
int a[N],d[N],f[N],g[N];
vector<int>e[N];
V add_edge(int x,int y){
	e[x].push_back(y),d[x]++;
	e[y].push_back(x),d[y]++;
}
V dfs(int u,int fa=0){
	if(d[u]==1)return void(f[u]=1);
	int cnt=0;
	for(int v:e[u])if(v!=fa)
		dfs(v,u),cnt+=d[v]==1,f[u]|=g[v],g[u]|=f[v];
	ans-=max(0,cnt-1);
}
int main(){
	scanf("%d",&n),ans=n-1;
	for(int x,y;--n;add_edge(x,y))scanf("%d%d",&x,&y);
	while(d[++rt]==1);
	dfs(rt),cout<<1+2*f[rt]*g[rt]<<' '<<ans;
	return 0;
}