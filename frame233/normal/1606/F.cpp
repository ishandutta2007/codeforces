#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
std::vector<int> e[N];int Fa[N],f[N],dfn[N],siz[N],id,ans[N];
int fa[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int x,int fa){
	if(fa)e[x].erase(std::find(e[x].begin(),e[x].end(),fa));
	f[x]=SZ(e[x]),Fa[x]=fa,siz[x]=1,dfn[x]=++id;for(auto v:e[x])if(v!=fa)dfs(v,x),siz[x]+=siz[v];
}
struct node{
	int c,k;
	inline node operator + (const node &o)const{return {c+o.c,k+o.k};}
	inline node operator - (const node &o)const{return {c-o.c,k-o.k};}
};
node c[N];void add(int x,node C){++x;for(;x<N;x+=lowbit(x))c[x]=c[x]+C;}
node ASK(int x){++x;node ans={0,0};for(;x;x-=lowbit(x))ans=ans+c[x];return ans;}
std::vector<int> vec[N];bool vis[N];int tim[N];
struct qry{int v,id;};std::vector<qry> Q[N];
inline void upd(int x,int y,const node &C){add(dfn[x],C),add(dfn[Fa[y]],(node){0,0}-C);}
inline node ask(int x){return ASK(dfn[x]+siz[x]-1)-ASK(dfn[x]-1);}
int main(){
	int n;read(n);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs(1,0);for(int i=2;i<=n;++i)vec[f[i]].pb(i),tim[i]=f[i];
	int q;read(q);for(int i=1,x,y;i<=q;++i)read(x,y),Q[y+1].pb({x,i});
	for(int i=1;i<=n;++i)upd(i,i,{f[i],0});
	std::iota(fa+1,fa+n+1,1);
	for(int m=2e5+1;m>=1;--m){
		while(!vec[m].empty()){
			int x=vec[m].back();vec[m].pop_back();if(vis[x]||m!=tim[x])continue;
			vis[x]=1;int to=find(Fa[x]);fa[x]=to;node tmp=ask(x);++tmp.k;upd(Fa[x],to,tmp);
			if(to!=1)tmp=ask(to),vec[tim[to]=std::min(m,tmp.c/(tmp.k+1))].pb(to);
		}
		for(const auto &it:Q[m]){node tmp=ask(it.v);ans[it.id]=tmp.c-tmp.k*m;}
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}