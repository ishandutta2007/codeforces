#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define B inline bool
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=1e4+1;
int n,m,qwq,tot,f[N];
int h[N],pre[N],L[N],R[N],siz[N];
struct edge{int t,n;}e[N<<1];
struct node{
	int l,r,x;
	B operator<(const node&u)const{
		return l<u.l;
	}
}a[N];
V add_edge(rnt x,rnt y){e[++tot]=(edge){y,h[x]},h[x]=tot;}
V dfs(rnt u){
	REP(u){
		dfs(v),siz[u]+=siz[v];
		L[u]=min(L[u],L[v]);
		R[u]=max(R[u],R[v]);
	}
	a[++qwq]=(node){L[u],R[u],++siz[u]};
}
V input(){
	n=getint();rnt x;
	m=getint(),tot=0;
	FOR(i,1,m)L[i]=N,R[i]=h[i]=siz[i]=0;
	FOR(i,2,m)x=getint(),add_edge(x,i);
	FOR(i,1,n)x=getint(),L[x]=R[x]=i;
	siz[1]=-1,dfs(1);
	m=getint(),tot=0;
	FOR(i,1,m)L[i]=N,R[i]=h[i]=siz[i]=0;
	FOR(i,2,m)x=getint(),add_edge(x,i);
	FOR(i,1,n)x=getint(),L[x]=R[x]=i;
	siz[1]=-1,dfs(1);
}
V init(){sort(a+1,a+qwq+1);}
I lowbit(rnt x){return x&-x;}
V add(rnt x,rnt y){
	while(x<=n)f[x]=max(f[x],y),x+=lowbit(x);
}
I ask(rnt x){
	rnt out=0;
	while(x)out=max(out,f[x]),x^=lowbit(x);
	return out;
}
V work(){
	FOR(i,1,qwq){
		rnt l=a[i].l,r=a[i].r,x=a[i].x;
		f[r]=max(ask(r),ask(l-1)+x),add(r,f[r]);
	}
	cout<<ask(n);
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}