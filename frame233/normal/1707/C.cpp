#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef std::pair<int,int> pi;
int anc[N][20],dep[N],fa[N],siz[N],dfn[N],id,d[N];std::vector<int> e[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool check(int x,int y){return dfn[x]<=dfn[y]&&dfn[y]<dfn[x]+siz[x];}
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1,siz[x]=1,dfn[x]=++id,anc[x][0]=fa;for(int i=1;i<20;++i)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(auto v:e[x])if(v!=fa)dfs1(v,x),siz[x]+=siz[v];
}
inline void upd(int l,int r){if(l<=r)++d[l],--d[r+1];}
int main(){
	int n,m;read(n,m);std::iota(fa+1,fa+n+1,1);std::vector<pi> vec;
	for(int i=1,x,y;i<=m;++i){
		read(x,y);int u=find(x),v=find(y);
		if(u==v)vec.pb({x,y});
		else fa[u]=v,e[x].pb(y),e[y].pb(x);
	}
	dfs1(1,0);
	for(const auto &it:vec){
		int x=it.first,y=it.second;if(dfn[x]>dfn[y])std::swap(x,y);
		if(check(x,y)){
			int z=y;for(int i=19;i>=0;--i)if(anc[z][i]&&dep[anc[z][i]]>dep[x])z=anc[z][i];
			upd(dfn[z],dfn[y]-1),upd(dfn[y]+siz[y],dfn[z]+siz[z]-1);
		}
		else upd(1,dfn[x]-1),upd(dfn[x]+siz[x],dfn[y]-1),upd(dfn[y]+siz[y],n);
	}
	for(int i=1;i<=n;++i)d[i]+=d[i-1];
	for(int i=1;i<=n;++i)putchar(d[dfn[i]]==0?'1':'0');
	putchar('\n');
	return 0;
}