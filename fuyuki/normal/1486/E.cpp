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
const int N=2e5+1,M=1e6+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
vector<P>e[M];
int n,m,tot,id[51][N];
V add_edge(int x,int y,int w){
	e[x].push_back(P(y,w));
}
V input(){
	n=getint(),m=getint(),tot=n+1;
	for(int x,y,w,p;m--;){
		x=getint(),y=getint(),w=getint();
		if(!id[w][y])id[w][y]=tot,tot+=2;
		add_edge(x,id[w][y],w*w);
		add_edge(id[w][y]+1,x,w*w);
		if(!id[w][x])id[w][x]=tot,tot+=2;
		add_edge(y,id[w][x],w*w);
		add_edge(id[w][x]+1,y,w*w);
	}
}
V init(){
	FOR(i,1,n)FOR(j,1,50)if(id[j][i])FOR(k,1,50)if(id[k][i])
		add_edge(id[j][i],id[k][i]+1,2*j*k);
}
int t[M];
ll w[M],d[M];
V upd(int x){t[x>>1]=w[t[x]]<w[t[x^1]]?t[x]:t[x^1];}
V update(int x){for(x+=tot-1;x^1;x>>=1)upd(x);}
V work(){
	FOR(i,1,tot)w[i]=1ll<<60,d[i]=-1;
	w[1]=0;
	FOR(i,1,tot)t[i+tot-1]=i;
	ROF(i,tot+tot-1,2)upd(i);
	for(int u,v,x;w[t[1]]<=1ll<<50;){
		u=t[1],d[u]=w[u];
		for(auto p:e[u]){
			v=p.first,x=p.second;
			if(d[v]>=0)continue;
			w[v]=min(w[v],w[u]+x);
			update(v);
		}
		w[u]=1ll<<60,update(u);
	}
	FOR(i,1,n)cout<<d[i]<<' ';
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