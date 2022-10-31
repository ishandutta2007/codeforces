#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=400005,inf=0x3f3f3f3f;
struct edge{int u,v,w;inline bool operator < (const edge &o)const{return w<o.w;}};
int fa[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
std::vector<int> e[N],B[N];int w[N];
int dep[N],f[N<<1][20],Log2[N<<1],fir[N],dfn[N],rev[N],id,pos;
inline int _min(int x,int y){return dep[x]<dep[y]?x:y;}
void dfs1(int x,int fa){
	if(!w[x])dfn[x]=++id,rev[id]=x;
	f[++pos][0]=x,dep[x]=dep[fa]+1,fir[x]=pos;
	for(auto v:e[x])if(v!=fa)dfs1(v,x),f[++pos][0]=x;
}
inline int lca(int l,int r){
	l=fir[l],r=fir[r];if(l>r)std::swap(l,r);
	int k=Log2[r-l+1];return _min(f[l][k],f[r-(1<<k)+1][k]);
}
void build(int n,std::vector<edge> E){
	for(int i=1;i<=n;++i)w[i]=0;
	for(int i=1;i<=n*2;++i)e[i].clear();
	std::sort(E.begin(),E.end());
	std::iota(fa+1,fa+n+1,1);int u,v,w,nc=n;
	for(const auto &it:E){
		u=it.u,v=it.v,w=it.w;int x=find(u),y=find(v);
		if(x!=y){int u=++nc;fa[x]=fa[y]=fa[u]=u,e[u].pb(x),e[u].pb(y),::w[u]=w;}
	}
	id=0,pos=0,dfs1(nc,0);
	for(int i=pos;i>=1;--i)for(int j=1;j<20&&i+(1<<(j-1))<=pos;++j)f[i][j]=_min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int pre[N],suf[N];bool mark[N];edge mn[N];
void MAIN(){
	int n,m;read(n,m);std::vector<edge> E(m),EE;
	for(int i=0;i<m;++i)read(E[i].u,E[i].v,E[i].w);
	build(n,E);int c=n;std::iota(fa+1,fa+n+1,1);
	for(int i=0;i<m;++i){
		int u=dfn[E[i].u],v=dfn[E[i].v];
		B[u].pb(v),B[v].pb(u);
	}
	while(c>1){
		for(int i=1;i<=n;++i)pre[i]=i>1&&find(i)==find(i-1)?pre[i-1]:i-1;
		for(int i=n;i>=1;--i)suf[i]=i<n&&find(i)==find(i+1)?suf[i+1]:i+1;
		for(int i=1;i<=n;++i)mn[i]={-1,-1,inf};
		for(int i=1;i<=n;++i){
			int bel=find(i);
			for(auto v:B[i])mark[v]=1;
			for(int j=suf[i];j<=n;){
				if(find(j)==bel){j=suf[j];continue;}
				if(mark[j]){++j;continue;}
				chmin(mn[bel],{i,j,w[lca(rev[i],rev[j])]});break;
			}
			for(int j=pre[i];j>=1;){
				if(find(j)==bel){j=pre[j];continue;}
				if(mark[j]){--j;continue;}
				chmin(mn[bel],{i,j,w[lca(rev[i],rev[j])]});break;
			}
			for(auto v:B[i])mark[v]=0;
		}
		for(int i=1;i<=n;++i)if(fa[i]==i){
			int u=find(mn[i].u),v=find(mn[i].v);
			if(u!=v)fa[u]=v,EE.pb(mn[i]),--c;
		}
	}
	for(auto &&it:EE)it.u=rev[it.u],it.v=rev[it.v];
	build(n,EE);for(int i=0;i<m;++i)printf("%d ",w[lca(E[i].u,E[i].v)]);
	printf("\n");for(int i=1;i<=n;++i)B[i].clear();
}
int main(){
	for(int i=2;i<N<<1;++i)Log2[i]=Log2[i>>1]+1;
	int _;read(_);
	while(_--)MAIN();
	return 0;
}