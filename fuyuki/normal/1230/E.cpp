#include<cstdio>
#include<iostream>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
LL getint(){
	re ll _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e5+1,logN=50,mod=1e9+7;
int n,m,tot,ans,h[N];ll a[N];
struct edge{int t,n;}e[N<<1];
V add_edge(rnt x,rnt y){
	e[++tot]=(edge){y,h[x]},h[x]=tot;
	e[++tot]=(edge){x,h[y]},h[y]=tot;
}
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();rnt x,y;
	FOR(i,2,n)x=getint(),y=getint(),add_edge(x,y);
}
V check(int&x){x-=mod,x+=x>>31&mod;}
ll gcd(ll x,ll y){while(x&&y)(x>y)?(x%=y):(y%=x);return x|y;}
struct P{
	int siz[logN],top;
	ll val[logN];
	P(){val[0]=siz[0]=-1;}
	V push(const ll&w,const int&x){
		if(val[top]==w)siz[top]+=x;
		else top++,val[top]=w,siz[top]=x;
	}
	I getsum(){
		rnt out=0;
		FOR(i,1,top)check(out+=val[i]*siz[i]%mod);
		return out;
	}
}t[N];
V dfs(rnt u,rnt fa){
	FOR(i,1,t[fa].top)t[u].push(gcd(a[u],t[fa].val[i]),t[fa].siz[i]);
	t[u].push(a[u],1);
	check(ans+=t[u].getsum());
	REP(u)dfs(v,u);
}
V work(){dfs(1,0),cout<<ans;}
int main(){
//	freopen("test.in","r",stdin);
	input();
	work();
	return 0;
}