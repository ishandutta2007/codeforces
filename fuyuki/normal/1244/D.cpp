#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re //register
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt _=h[u],v;v=e[_].t,_;_=e[_].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e5+1;
int n,tot,h[N],c[N][3],d[N];
struct edge{int t,n;}e[N<<1];
V add_edge(rnt x,rnt y){
	e[++tot]=(edge){y,h[x]},h[x]=tot;
	e[++tot]=(edge){x,h[y]},h[y]=tot;
	d[x]++,d[y]++;
}
V input(){
	n=getint();
	FOR(i,1,n)c[i][0]=getint();
	FOR(i,1,n)c[i][1]=getint();
	FOR(i,1,n)c[i][2]=getint();
	rnt x,y;
	FOR(i,2,n)x=getint(),y=getint(),add_edge(x,y);
}
V init(){
	
}
ll min(const ll&x,const ll&y){return x<y?x:y;}
ll f[N][3][3];
V dfs(rnt u,rnt fa){
	int flag=0;
	REP(u){
		dfs(v,u);
		if(flag)cout<<"-1",exit(0);
		flag=1;
		FOR(i,0,2)FOR(j,0,2)if(i^j)f[u][3^i^j][i]+=f[v][i][j];
	}
	FOR(j,0,2)FOR(i,0,2)f[u][j][i]+=c[u][j];
}
int co[N];
V paint(rnt u,rnt fa,rnt x,rnt y){
	co[u]=x;
	REP(u)paint(v,u,y,3^x^y);
}
V work(){
	rnt st,x,y;
	FOR(i,1,n)if(d[i]==1)st=i;
	dfs(st,0);
	ll ans=1ll<<62;
	FOR(i,0,2)FOR(j,0,2)if(i^j)
		if(ans>f[st][i][j])x=i,y=j,ans=f[st][i][j];
	cout<<ans<<'\n';
	paint(st,0,x,y);
	FOR(i,1,n)cout<<co[i]+1<<' ';
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	input();
	init();
	work();
	return 0;
}