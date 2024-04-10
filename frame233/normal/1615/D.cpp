#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005;typedef std::pair<int,int> pi;
std::vector<pi> e[N],G[N];int b[N],c[N],fa[N],a[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int x,int fa){
	for(auto [v,w]:e[x])if(v!=fa){
		if(w==-1)b[v]=v,c[v]=0;
		else b[v]=b[x],c[v]=c[x]^(__builtin_parity(w));
		dfs(v,x);
	}
}
void merge(int x,int y){x=find(x),y=find(y),fa[x]=y;}
inline void addedge(int u,int v,int z){G[u].pb({v,z}),G[v].pb({u,z});}
bool flag;
void Dfs(int x,int w){
	if(a[x]!=-1){
		if(a[x]!=w)flag=1;
		return;
	}
	a[x]=w;for(auto [v,z]:G[x])Dfs(v,z^w);
}
void DFS(int x,int fa){
	for(auto [v,w]:e[x])if(v!=fa){
		if(w==-1)printf("%d %d %d\n",x,v,a[x]^a[v]);
		else printf("%d %d %d\n",x,v,w);
		DFS(v,x);
	}
}
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)e[i].clear(),G[i].clear();
	for(int i=1,x,y,z;i<n;++i)read(x,y,z),e[x].pb({y,z}),e[y].pb({x,z});
	b[1]=1,c[1]=0,dfs(1,0);
	for(int i=1,x,y,z;i<=m;++i)read(x,y,z),z^=c[x]^c[y],addedge(b[x],b[y],z);
	memset(a,-1,(n+3)<<2);
	flag=0;for(int i=1;i<=n;++i)if(b[i]==i&&a[i]==-1)Dfs(i,0);
	if(flag)return puts("NO"),void();
	puts("YES");for(int i=1;i<=n;++i)a[i]=a[b[i]]^c[i];
	DFS(1,0);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}