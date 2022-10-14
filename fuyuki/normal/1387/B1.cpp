#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=2e5+1;
int n,x,y;
vector<int>e[N];
int f[N],g[N],a[N],tag[N];
V add_edge(int x,int y){e[x].push_back(y),e[y].push_back(x);}
V dfs1(int u,int fa=0){
	a[u]=u,f[u]=1;
	for(int v:e[u])if(v^fa)
		dfs1(v,u),f[u]+=g[v],g[u]+=max(f[v],g[v]);
}
V dfs2(int u,int fa=0){
	if(!tag[u])tag[u]=(f[u]>g[u])+1;
	if(tag[u]==2)swap(a[u],fa?a[fa]:a[e[u].back()]);
	for(int v:e[u])if(v^fa)tag[v]=tag[u]==2,dfs2(v,u);
}
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d",&n);
	FOR(i,2,n)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs1(1),cout<<max(f[1],g[1])*2<<'\n',dfs2(1);
	FOR(i,1,n)cout<<a[i]<<' ';
	return 0;
}