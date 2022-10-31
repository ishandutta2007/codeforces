#include<bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005,NC=(1<<20)+5,NCC=N*21;typedef long long ll;
char s[N];int ch[N][26],fa[N],len[N],nc=1,last=1,v[N],n,q,val[N];std::vector<int> e[N];ll ans[N];
struct BIT{
	ll c[N];void add(int x,ll C){for(;x<N;x+=lowbit(x))c[x]+=C;}
	ll ask(int x){ll ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
	inline ll ask(int l,int r){return ask(r)-ask(l-1);}
};
void extend(int c){
	int u=++nc,p=last;len[u]=len[p]+1;
	while(p&&!ch[p][c])ch[p][c]=u,p=fa[p];
	if(!p)fa[u]=1;
	else{
		int q=ch[p][c];
		if(len[q]==len[p]+1)fa[u]=q;
		else{
			int cl=++nc;memcpy(ch[cl],ch[q],104),len[cl]=len[p]+1,fa[cl]=fa[q],fa[q]=fa[u]=cl;
			while(p&&ch[p][c]==q)ch[p][c]=cl,p=fa[p];
		}
	}
	last=u;
}
int siz[N],Fa[N],dep[N],son[N],top[N],anc[N][20],dfn[N],id,rev[N],rt[N],rrev[N];
void dfs1(int x,int fa){
	siz[x]=1,Fa[x]=fa,dep[x]=dep[fa]+1,anc[x][0]=fa,val[x]=len[x]-len[fa];
	for(int i=1;i<20;++i)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(auto v:e[x])if(v!=fa){
		dfs1(v,x),siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
void dfs2(int x,int topf){
	dfn[x]=++id,rev[id]=x,top[x]=topf;if(son[x])dfs2(son[x],topf);
	for(auto v:e[x])if(!top[v])dfs2(v,v);
}
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
namespace DS1{
ll s[NC],sum[NC];int tag[NC];
inline void upd(int u,int C){sum[u]+=s[u]*C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void build(int l,int r,int u){
	if(l==r){s[u]=val[rev[l]];return;}
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u));
	s[u]=s[ls(u)]+s[rs(u)];
}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	sum[u]=sum[ls(u)]+sum[rs(u)];
}
ll ask(int L,int R,int l,int r,int u){
	if(L<=l&&r<=R)return sum[u];
	int mid=(l+r)>>1;pushdown(u);
	return (L<=mid?ask(L,R,l,mid,ls(u)):0)+(R>mid?ask(L,R,mid+1,r,rs(u)):0);
}
}
namespace DS2{
int ls[NCC],rs[NCC],f[NCC],nc;ll g[NCC];
void Update(int &rt,int pos,int l,int r){
	int u=++nc;ls[u]=ls[rt],rs[u]=rs[rt],f[u]=f[rt]+1,g[u]=g[rt]+pos,rt=u;if(l==r)return;
	int mid=(l+r)>>1;pos<=mid?Update(ls[rt],pos,l,mid):Update(rs[rt],pos,mid+1,r);
}
ll ask1(int L,int R,int l,int r,int u,int v){
	if(!u)return 0;
	if(L<=l&&r<=R)return f[u]-f[v];
	int mid=(l+r)>>1;return (L<=mid?ask1(L,R,l,mid,ls[u],ls[v]):0)+(R>mid?ask1(L,R,mid+1,r,rs[u],rs[v]):0);
}
ll ask2(int L,int R,int C,int l,int r,int u,int v){
	if(!u)return 0;
	if(L<=l&&r<=R)return (1LL*C*f[u]-g[u])-(1LL*C*f[v]-g[v]);
	int mid=(l+r)>>1;return (L<=mid?ask2(L,R,C,l,mid,ls[u],ls[v]):0)+(R>mid?ask2(L,R,C,mid+1,r,rs[u],rs[v]):0);
}
}
namespace DS3{
BIT tr3,tr4;
inline void upd(int x,int C){++x;tr3.add(x,C),tr4.add(x,C*(x-1));}
inline ll ask(int L,int R,int C){++L,++R;return 1LL*C*tr3.ask(L,R)-tr4.ask(L,R);}
}
struct qry1{int x,r,id;};std::vector<qry1> Q1[N];BIT tr1,tr2;
struct qry2{int x,id;};std::vector<qry2> Q2[N],Q3[N];
void solve1(){
	for(int i=n;i>=1;--i){
		int x=v[i];tr1.add(dfn[x],1),tr2.add(dfn[x],i);
		for(const auto &it:Q1[i])ans[it.id]+=tr1.ask(dfn[it.x],dfn[it.x]+siz[it.x]-1)*(it.r+1)-tr2.ask(dfn[it.x],dfn[it.x]+siz[it.x]-1);
	}
	memset(tr1.c,0,sizeof(tr1.c)),memset(tr2.c,0,sizeof(tr2.c));
	for(int i=1;i<=n;++i){
		for(const auto &it:Q1[i])ans[it.id]+=tr1.ask(dfn[it.x],dfn[it.x]+siz[it.x]-1)*len[Fa[it.x]];
		int x=v[i];tr1.add(dfn[x],1),tr2.add(dfn[x],i);
	}
}
void solve2(){
	DS1::build(1,nc,1);
	for(int i=1;i<=n;++i){
		int x=v[i];while(x)DS1::Update(dfn[top[x]],dfn[x],1,1,nc,1),x=Fa[top[x]];
		for(const auto &it:Q2[i]){int y=it.x;while(top[y])ans[it.id]-=DS1::ask(dfn[top[y]],dfn[y],1,nc,1),y=Fa[top[y]];}
	}
}
int DD,coef;ll tot;
inline void push(int x){if(rrev[x])DS3::upd(rrev[x]-1+DD,coef),tot+=DD;}
void dfs3(int x){push(x);for(auto v:e[x])dfs3(v);}
void solve3(){
	for(int u=1;u<=nc;++u)if(top[u]==u){
		coef=1,tot=0;
		for(int i=u;i;i=son[i]){
			DD=len[i],push(i);
			for(auto v:e[i])if(v!=son[i])dfs3(v);
			for(const auto &it:Q3[i])ans[it.id]+=tot+DS3::ask(it.x,n,it.x);
		}
		coef=-1;
		for(int i=u;i;i=son[i]){
			DD=len[i],push(i);
			for(auto v:e[i])if(v!=son[i])dfs3(v);
		}
	}
}
ll get(int l,int r,int d,int rr){
	ll ans=rr-d+1>=1?1LL*d*DS2::ask1(1,rr-d+1,1,n,rt[r],rt[l-1]):0;
	return ans+(rr-d+2<=n?DS2::ask2(std::max(rr-d+2,1),n,rr+1,1,n,rt[r],rt[l-1]):0);
}
int main(){
	scanf("%s",s+1),n=strlen(s+1),read(q);
	for(int i=n;i>=1;--i)extend(s[i]-'a'),v[i]=last,rrev[v[i]]=i;
	for(int i=2;i<=nc;++i)e[fa[i]].pb(i);
	dfs1(1,0),dfs2(1,1);
	for(int i=1;i<=nc;++i){rt[i]=rt[i-1];if(rrev[rev[i]])DS2::Update(rt[i],rrev[rev[i]],1,n);}
	for(int i=0,l,r;i<q;++i){
		read(l,r),ans[i]=1LL*(n-r)*(n-r-1)/2;int x=v[l];
		for(int j=19;j>=0;--j)if(len[anc[x][j]]>=r-l+1)x=anc[x][j];
		Q1[l].pb({x,r,i}),Q2[l-1].pb({Fa[x],i});
		while(Fa[x]){
			ans[i]+=get(dfn[Fa[x]],dfn[Fa[x]]+siz[Fa[x]]-1,len[Fa[x]],r)-get(dfn[x],dfn[x]+siz[x]-1,len[Fa[x]],r),x=Fa[x];
			if(x!=top[x])Q3[Fa[x]].pb({r,i});
			x=top[x];
		}
	}
	solve1(),solve2(),solve3();
	for(int i=0;i<q;++i)printf("%lld\n",ans[i]);
	return 0;
}