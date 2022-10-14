#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define REP(u) for(rnt _=h[u],v;v=e[_].t,_;_=e[_].n)if(v^pre[u])
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e5+1,mod=1e9+7;
V check(int&x){x-=mod,x+=x>>31&mod;}
int n,ans,tot,sum,now,len[N],h[N],w[N];
int a[N],b[N],c[N],d[N],inv[N],pre[N],siz[N],wes[N],dep[N];
struct edge{int t,n;}e[N<<1];
V add_edge(rnt x,rnt y){
	e[++tot]=(edge){y,h[x]},h[x]=tot;
	e[++tot]=(edge){x,h[y]},h[y]=tot;
}
V input(){
	n=getint();rnt x,y;
	FOR(i,1,n)a[i]=getint(),b[i]=getint(),len[i]=b[i]-a[i]+1;
	FOR(i,2,n)x=getint(),y=getint(),add_edge(x,y);
}
V init(rnt u){
	siz[u]=1,dep[u]=dep[pre[u]]+1;
	REP(u){
		pre[v]=u,init(v),siz[u]+=siz[v];
		if(siz[v]>siz[wes[u]])wes[u]=v;
	}
}
I lowbit(const int&x){return x&-x;}
V add(rnt x,rnt y){
	for(rnt w=1ll*x*y%mod;x<N;x+=lowbit(x))
		check(c[x]+=w),check(d[x]+=y);
}
I ask(rnt x){
	rnt out=0,tmp=0;
	for(rnt i=x;i;i^=lowbit(i))
		check(tmp+=d[i]),check(out+=c[i]);
	check(out=1ll*(x+1)*tmp%mod+mod-out);
	return out;
}
I pw(const int&x){return 1ll*x*x%mod;}
V add(rnt l,rnt r,rnt x){add(l,x),add(r+1,mod-x);}
I ask(rnt l,rnt r){return (ask(r)-ask(l-1)+mod)%mod;}
V init(){
	inv[0]=1,inv[1]=1,sum=1,init(1);
	FOR(i,2,N-1)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,1,n)sum=1ll*sum*len[i]%mod;
	FOR(i,1,n)add(a[i],b[i],w[i]=1ll*sum*inv[len[i]]%mod);
	FOR(i,1,n)check(ans+=1ll*(mod+ask(a[i],b[i])-sum)*inv[len[i]]%mod*dep[i]%mod);
	FOR(i,1,N-1)c[i]=d[i]=0;
}
V once(rnt u){check(ans+=mod-2ll*now*ask(a[u],b[u])%mod*inv[len[u]]%mod);}
V clean(rnt u){add(a[u],b[u],mod-w[u]);REP(u)clean(v);}
V calc(rnt u){once(u);REP(u)calc(v);}
V add(rnt u){add(a[u],b[u],w[u]);REP(u)add(v);}
V dfs(rnt u){
	REP(u)if(v!=wes[u])dfs(v),clean(v);
	if(wes[u])dfs(wes[u]);
	now=dep[u],once(u),add(a[u],b[u],w[u]);
	REP(u)if(v!=wes[u])calc(v),add(v);
}
V work(){dfs(1),cout<<ans;}
int main(){
	input();
	init();
	work();
	return 0;
}