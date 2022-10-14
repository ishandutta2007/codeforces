#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
LL getint(){
	re ll _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e6+100;
int n,k,tot,h[N];
struct edge{int t,n,w;}e[N];
V clean(){tot=0;FOR(i,1,n)h[i]=0;}
V add_edge(rnt x,rnt y,rnt w){
	e[++tot]=(edge){y,h[x],w},h[x]=tot;
	e[++tot]=(edge){x,h[y],w},h[y]=tot;
}
V input(){
	n=getint(),k=getint();
	rnt x,y,z;
	FOR(i,2,n){
		x=getint(),y=getint(),z=getint(),add_edge(x,y,z);
	}
}
//I max(const int&x,const int&y){return x>y?x:y;}
//I min(const int&x,const int&y){return x<y?x:y;}
V init(){}
ll f[N],g[N];int cnt;
struct P{
	ll x,y;
	B operator<(const P&u)const{
		return x-y>u.x-u.y;
	}
}tmp[N];
V dfs(rnt u,rnt fa){
	REP(u)dfs(v,u);
	cnt=0,f[u]=g[u]=0;
	REP(u)tmp[++cnt]=(P){g[v]+e[i].w,f[v]};
	sort(tmp+1,tmp+1+cnt);rnt p=k;
	FOR(i,1,cnt)
		if(p>1&&tmp[i].x>tmp[i].y){
			f[u]+=tmp[i].x;
			g[u]+=tmp[i].x;
			p--;
		}
		else if(p==1&&tmp[i].x>tmp[i].y){
			f[u]+=tmp[i].x;
			g[u]+=tmp[i].y;
			p--;
		}
		else{
			f[u]+=tmp[i].y;
			g[u]+=tmp[i].y;
		}
	f[u]=max(f[u],g[u]);
}
V work(){
	dfs(1,0),cout<<max(f[1],g[1])<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	int T;T=getint();
	while(T--){
		clean();
		input();
		init();
		work();
	}
	return 0;
}