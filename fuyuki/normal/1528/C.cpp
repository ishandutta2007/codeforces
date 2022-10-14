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
const int N=3e5+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
vector<int>e[N];
int T,n,tot,ans;
int a[N],b[N],f[20][N],dfn[N],dep[N];
V add_edge(int x,int y){e[x].push_back(y);}
V input(){
	n=getint(),tot=ans=0;
	FOR(i,2,n)a[i]=getint();
	FOR(i,2,n)b[i]=getint();
}
V dfs1(int u){
	dfn[u]=++tot;
	for(int v:e[u])dep[v]=dep[u]+1,dfs1(v);
}
V init(){
	FOR(i,2,n)add_edge(b[i],i);
	dfs1(1);
	FOR(i,1,n)f[0][i]=b[i],e[i].clear();
	FOR(i,1,19)FOR(j,1,n)f[i][j]=f[i-1][f[i-1][j]];
}
I lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	ROF(i,19,0)if(dep[x]-dep[y]>>i)x=f[i][x];
	if(x==y)return x;
	ROF(i,19,0)if(f[i][x]!=f[i][y])x=f[i][x],y=f[i][y];
	return b[x];
}
set<P>mp;
#define IT set<P>::iterator
V dfs2(int u){
	int x=0,y=0;
	IT it=mp.upper_bound(P(dfn[u],u));
	if(it==mp.end()||lca(u,it->second)!=u) 
		x=u,mp.insert(P(dfn[x],x));
	it=mp.lower_bound(P(dfn[u],u));
	if(it!=mp.begin()){
		--it;
		if(lca(u,it->second)==it->second)
			y=it->second,mp.erase(P(dfn[y],y));
	}
	cmax(ans,mp.size());
	for(int v:e[u])dfs2(v);
	if(x)mp.erase(P(dfn[x],x));
	if(y)mp.insert(P(dfn[y],y));
}
V work(){
	FOR(i,2,n)add_edge(a[i],i);
	dfs2(1),mp.clear();
	FOR(i,1,n)e[i].clear();
	cout<<ans<<'\n';
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