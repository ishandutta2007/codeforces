/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
const int MAXN = 2e5 + 10; 
int n,m,q,u,v,cnt,col[MAXN],dep[MAXN],top[MAXN],fa[MAXN][20];
int dfs_time,num,low[MAXN],dfn[MAXN];
int a[MAXN],b[MAXN],vis[MAXN];
vector<int> G[MAXN];
stack<int> S;
struct Edge{int to,next;}e[MAXN<<1];
int tot=1,head[MAXN];
inl void add(int u,int v){
	e[++tot]=(Edge){v,head[u]},head[u]=tot;
}
inl void tarjan(int u,int fa){
	dfn[u]=low[u]=++dfs_time;
	S.push(u);
	trv(i,u) if(i!=fa && (i^1)!=fa) {
		int v=e[i].to;
		if(!dfn[v]) tarjan(v,i),ylmin(low[u],low[v]);
		else ylmin(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]) {
		col[u]=++num;
		while(S.top()!=u){
			col[S.top()]=num;
			S.pop();
		}
		S.pop();
	}
}
inl void dfs(int u,int f,int nw){
	dep[u]=dep[f]+1,fa[u][0]=f,top[u]=nw;
	for(auto v:G[u]) if(v!=f) dfs(v,u,nw);
}
inl void init(){
	rep(i,1,19) rep(j,1,n) fa[j][i]=fa[fa[j][i-1]][i-1];
}
inl int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	per(i,19,0) if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	per(i,19,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inl void getsum(int u,int fa){
	for(auto v:G[u]) if(v!=fa) {
		getsum(v,u);
		a[u]+=a[v];
		b[u]+=b[v];
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m),read(q);
	rep(i,1,m) read(u),read(v),add(u,v),add(v,u);
	rep(i,1,n) if(!dfn[i]) tarjan(i,0);
	rep(i,1,n) trv(j,i) {
		int v=e[j].to;
		if(col[v]!=col[i]) G[col[v]].push_back(col[i]),G[col[i]].push_back(col[v]);
	}
	rep(i,1,num) sort(all(G[i])), G[i].erase(unique(all(G[i])), G[i].end());
	rep(i,1,num) if(!dep[i]) dfs(i,i,++cnt);
	init();
	rep(i,1,q) {
		read(u),read(v);
		u=col[u],v=col[v];
		if(top[u]!=top[v]) return puts("No"),0;
		int w=lca(u,v);
		a[w]--,a[u]++;
		b[w]--,b[v]++;
	}
	rep(i,1,num) if(fa[i][0]==i) getsum(i,i);
	rep(i,1,num) if(a[i] && b[i]) return puts("No"),0;
	puts("Yes");
	return 0;
}