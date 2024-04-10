#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt _=h[u],v;v=e[_].t,_;_=e[_].n)if(v!=nxt[u])
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e6+1;
int n,tot,tp;
int h[N],pre[N],nxt[N],out[N],in[N],sta[N],dep[N];
struct edge{int t,n;}e[N];
V add_edge(rnt x,rnt y){
	e[++tot]=(edge){y,h[x]},h[x]=tot;
}
V dfs(rnt u){
	dep[u]=1,nxt[u]=-1;
	REP(u){
		dfs(v);
		if(!~nxt[u]||dep[v]>dep[nxt[u]])
			dep[u]=dep[v]+1,nxt[u]=v;
	}
}
V link(rnt x,rnt y){pre[y]=x,nxt[x]=y;}
int main(){
	n=getint();
	FOR(i,1,n-1)pre[i]=getint(),add_edge(pre[i],i);
	dfs(0),tot=0;
	for(rnt p=0;~p&&(in[p]=1);p=nxt[p])
		REP(p)sta[++tp]=v;
	while(tp){
		rnt u=sta[tp--];
		link(u,out[++tot]=nxt[pre[u]]),link(pre[u],u);
		REP(u)sta[++tp]=v;
	}
	for(rnt p=0;~p;p=nxt[p])cout<<p<<' ';
	cout<<'\n'<<tot<<'\n';
	ROF(i,tot,1)cout<<out[i]<<' ';
	return 0;
}