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
const int N=2e5+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int T,n;
int l[N],r[N];
ll f[N],g[N];
vector<int>e[N];
V add_edge(int x,int y){
	e[x].push_back(y);
	e[y].push_back(x);
}
V input(){
	n=getint();
	FOR(i,1,n)e[i].clear();
	FOR(i,1,n)l[i]=getint(),r[i]=getint();
	FOR(i,2,n)add_edge(getint(),getint());
}
V dfs(int u,int fa=0){
	f[u]=g[u]=0;
	for(int v:e[u])if(v!=fa){
		dfs(v,u);
		f[u]+=max(abs(l[u]-l[v])+f[v],abs(l[u]-r[v])+g[v]);
		g[u]+=max(abs(r[u]-l[v])+f[v],abs(r[u]-r[v])+g[v]);
	}
}
V init(){
	dfs(1);
	cout<<max(f[1],g[1])<<'\n';
}
V work(){
	
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