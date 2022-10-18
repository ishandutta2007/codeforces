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
const int N=5e5+1,INF=0x3f3f3f3f;
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
int T,n,a[N],f[N],g[N];
struct node{
	int w,tag,val;
	V clear(){w=tag=val=0;}
	V add(){cmax(val,w+1),w=-INF,tag=1;}
}t[N<<2];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
}
#define lc p<<1
#define rc lc|1
#define root 1,1,n
#define lson lc,L,mid
#define rson rc,mid+1,R
V build(int p,int L,int R){
	if(t[p].clear(),L==R)return;
	int mid=L+R>>1;
	build(lson),build(rson);
}
V init(){build(root);}
V upd(int p){
	t[p].val=max(t[lc].val,t[rc].val);
	t[p].w=max(t[lc].w,t[rc].w);
}
V psd(int p){if(t[p].tag)t[lc].add(),t[rc].add(),t[p].tag=0;}
V modify(int p,int L,int R,int l,int r){
	if(L==l&&R==r)
		return t[p].add();
	int mid=L+R>>1;psd(p);
	if(l>mid)return modify(rson,l,r),upd(p);
	if(r<=mid)return modify(lson,l,r),upd(p);
	modify(lson,l,mid),modify(rson,mid+1,r),upd(p);
}
V test(int p,int L,int R,int x,int w){
	if(L==R)return cmax(t[p].w,w),cmax(t[p].val,w);
	int mid=L+R>>1;psd(p);
	if(x>mid)test(rson,x,w);
	else test(lson,x,w);
	upd(p);
}
I ask(int p,int L,int R,int l,int r){
	if(L==l&&R==r)return t[p].val;
	int mid=L+R>>1;psd(p);
	if(l>mid)return ask(rson,l,r);
	if(r<=mid)return ask(lson,l,r);
	return max(ask(lson,l,mid),ask(rson,mid+1,r));
}
V work(){
	int x,w;
	FOR(i,1,n){
		x=a[i],w=ask(root,1,x);
		modify(root,1,x);
		test(root,x,w+1);
	}
	cout<<t[1].val<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}