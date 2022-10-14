#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
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
const int N=1e6+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
ll f[N],g[N];
int T,n,top,a[N],b[N];
struct node{
	int x,v,L,R;
}sta[N];

V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,n)b[i]=getint();
}
struct ele{
	ll v,d;
	V add(ll x){v+=x,d+=x;}
}t[N<<1];
#define lc p<<1
#define rc lc|1
#define lson lc,L,mid
#define rson rc,mid+1,R
#define root 1,1,n
const ll INF=1e12;
V upd(int p){t[p].v=max(t[lc].v,t[rc].v);}
V psd(int p){
	if(t[p].d)
		t[lc].add(t[p].d),t[rc].add(t[p].d),t[p].d=0;
}
V build(int p,int L,int R){
	if(L==R){
		if(L==1)t[p].v=0;
		else t[p].v=-INF;
		return;
	}
	int mid=L+R>>1;
	build(lson),build(rson),upd(p);
}
V init(){
	build(root);
}
V test(int p,int L,int R,int x){
	if(L==R)return void(t[p].v=f[x-1]);
	int mid=L+R>>1;
	x<=mid?test(lson,x):test(rson,x);
	upd(p);
}
V modify(int p,int L,int R,int l,int r,ll x){
	if(L==l&&R==r)return t[p].add(x);
	int mid=L+R>>1;
	if(l>mid)return modify(rson,l,r,x),upd(p);
	if(r<=mid)return modify(lson,l,r,x),upd(p);
	modify(lson,l,mid,x),modify(rson,mid+1,r,x),upd(p);
}
V ins(node v){
	while(top&&sta[top].x>v.x){
		v.L=sta[top].L;
		modify(root,sta[top].L,sta[top].R,-sta[top].v);
		top--;
	}
	sta[++top]=v;
	modify(root,sta[top].L,sta[top].R,sta[top].v);
}
V work(){
	FOR(i,1,n){
		ins((node){a[i],b[i],i,i});
		f[i]=t[1].v;
		if(i==n)cout<<f[i]<<'\n';
		else test(root,i+1);
	}
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}