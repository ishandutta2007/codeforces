#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+100,INF=1e7;
int n,m,tot;
int a[N],b[N],c[N],h[N];
int dep[N],tag[N],dfn[N],op[N],ed[N];
struct edge{int t,n,w;}e[N<<1];
V add_edge(int x,int y,int w){
	e[++tot]=(edge){y,h[x],w},h[x]=tot;
	e[++tot]=(edge){x,h[y],w},h[y]=tot;
}
V input(){
	n=getint();
	FOR(i,1,n-1)a[i]=getint(),b[i]=getint(),c[i]=getint(),add_edge(a[i],b[i],c[i]);
}
V dfs(int u,int fa=0){
	dfn[op[u]=ed[u]=++tot]=u;
	REP(u)if(v!=fa){
		dep[v]=dep[u]+1,tag[v]=tag[u]^e[i].w;
		dfs(v,u),dfn[ed[u]=++tot]=u;
	}
}
#define lc p<<1
#define rc lc|1
#define root 1,1,tot
#define lson lc,L,mid
#define rson rc,mid+1,R
struct ele{
	int maxn[2],minn;
	int lw[2],rw[2],val,tag;
	V init(int x,int w){
		lw[x]=rw[x]=-w,maxn[x]=minn=w;
		x^=1,tag=val=0,lw[x]=rw[x]=maxn[x]=-INF;
	}
	V rev(){tag^=1,swap(lw[0],lw[1]),swap(rw[0],rw[1]),swap(maxn[0],maxn[1]);}
}t[N<<2];
V cmax(int&x,int y){if(x-y>>31)x=y;}
V upd(int p){
	t[p].val=max(t[lc].val,t[rc].val);
	FOR(i,0,1){
		cmax(t[p].val,t[lc].lw[i]+t[rc].maxn[i]);
		cmax(t[p].val,t[rc].rw[i]+t[lc].maxn[i]);
		t[p].maxn[i]=max(t[lc].maxn[i],t[rc].maxn[i]);
		t[p].lw[i]=max(t[lc].maxn[i]-t[rc].minn*2,max(t[lc].lw[i],t[rc].lw[i]));
		t[p].rw[i]=max(t[rc].maxn[i]-t[lc].minn*2,max(t[lc].rw[i],t[rc].rw[i]));
	}
}
V build(int p,int L,int R){
	if(L==R)return t[p].init(tag[dfn[L]],dep[dfn[R]]);
	int mid=L+R>>1;
	build(lson),build(rson),upd(p);
	t[p].minn=min(t[lc].minn,t[rc].minn);
}
V init(){
	tot=0,dfs(1),build(root);
	FOR(i,1,n-1)if(dep[a[i]]<dep[b[i]])swap(a[i],b[i]);
}
V psd(int p){if(t[p].tag)t[lc].rev(),t[rc].rev(),t[p].tag=0;}
V modify(int p,int L,int R,int l,int r){
	if(L==l&&R==r)return t[p].rev();
	int mid=L+R>>1;psd(p);
	if(l>mid)return modify(rson,l,r),upd(p);
	if(r<=mid)return modify(lson,l,r),upd(p);
	modify(lson,l,mid),modify(rson,mid+1,r),upd(p);
}
V work(){
	for(int x(m=getint());m--;cout<<t[1].val<<'\n')
		x=a[getint()],modify(root,op[x],ed[x]);
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}