#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<cstdio>
#include<vector>
#include<algorithm>
#define re register
using namespace std;
const int Mxdt=200000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
const int M=1e9+7;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
static char space[80000005],*sp=space;
template<typename T>
struct myalloc:allocator<T>{
    myalloc(){}
    template<typename T2>
    myalloc(const myalloc<T2> &a){}
    template<typename T2>
    myalloc<T>& operator=(const myalloc<T2> &a){return *this;}
    template<typename T2>
    struct rebind{typedef myalloc<T2> other;};
    inline T* allocate(size_t n){
        T *result=(T*)sp;sp+=n*sizeof(T);
        return result;
    }
    inline void deallocate(T* p,size_t n){}
};
int n,m,phi[200002],mu[200002],dep[200002],top[200002],son[200002],F[200002],ans,fa[200002],siz[200002],head[200002],a[200002],pri[200002],cnt,v[200002],p[200002],dfn[200002],tim,sss,stk[200002],tp,sum,s[200002],vis[200002];
vector<int,myalloc<int> >g[200002],f[200002];
struct edge{int to,next;}e[400002];
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs1(re int x,re int y){
	dep[x]=dep[y]+1,fa[x]=y,siz[x]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs1(e[i].to,x),siz[x]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
		}
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline void dfs2(re int x,re int y){
	top[x]=y,dfn[x]=++tim;
	if(son[x])dfs2(son[x],y);
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^fa[x]&&e[i].to^son[x])dfs2(e[i].to,e[i].to);
}
inline int lca(re int x,re int y){
	while(top[x]^top[y]){
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
inline int dis(re int x,re int y){return dep[x]+dep[y]-(dep[lca(x,y)]<<1);}
inline bool cmp(re int x,re int y){return dfn[x]<dfn[y];}
inline void dfs(re int x,re int y){
	if(vis[x])s[x]=phi[a[x]],add(sum,M-2ll*s[x]*s[x]%M*dep[x]%M);
	else s[x]=0;
	for(auto &z:f[x])if(z^y)dfs(z,x),add(sum,M-4ll*s[x]*s[z]%M*dep[x]%M),add(s[x],s[z]);
	f[x].clear();
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read(),p[a[i]]=i;
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),addd(x,y),addd(y,x);
	mu[1]=phi[1]=1;
	for(re int i=2;i<=n;++i){
		if(!v[i])mu[i]=M-1,phi[i]=i-1,pri[++sss]=i;
		for(re int j=1;j<=sss&&i*pri[j]<=n;++j){
			v[pri[j]*i]=1;
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1),mu[i*pri[j]]=M-mu[i];
		}
	}
	for(re int i=1;i<=n;++i)for(re int j=i;j<=n;j+=i)g[i].push_back(p[j]),add(F[j],1ll*i*ksm(phi[i],M-2)%M*mu[j/i]%M);
	dfs1(1,1),dfs2(1,1);
	for(re int i=1;i<=n;++i){
		sort(g[i].begin(),g[i].end(),cmp);
		for(re int j=0;j<g[i].size();++j)vis[g[i][j]]=1;
		tp=sum=0,stk[++tp]=1;
		for(re int j=0;j<g[i].size();++j){
			if(g[i][j]==1)continue;
			if(dfn[g[i][j]]>=dfn[stk[tp]]&&dfn[g[i][j]]<dfn[stk[tp]]+siz[stk[tp]])stk[++tp]=g[i][j];
			else{
				while(dfn[g[i][j]]<dfn[stk[tp-1]]||dfn[g[i][j]]>=dfn[stk[tp-1]]+siz[stk[tp-1]])f[stk[tp-1]].push_back(stk[tp]),--tp;
				re int xx=stk[tp--],yy;
				if((yy=lca(xx,g[i][j]))^stk[tp])stk[++tp]=yy;
				f[stk[tp]].push_back(xx),stk[++tp]=g[i][j];
			}
		}
		for(re int j=1;j<tp;++j)f[stk[j]].push_back(stk[j+1]);
		dfs(1,1);
		re int s=0;
		for(re int j=0;j<g[i].size();++j)add(s,phi[a[g[i][j]]]);
		for(re int j=0;j<g[i].size();++j)add(sum,2ll*phi[a[g[i][j]]]*dep[g[i][j]]%M*s%M);
		for(re int j=0;j<g[i].size();++j)vis[g[i][j]]=0;
		add(ans,1ll*sum*F[i]%M);
	}
	printf("%lld",1ll*ksm(1ll*n*(n-1)%M,M-2)*ans%M);
}