/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
const int MAXN = 1e4+10;
int n,m,u,v,cnt,head[MAXN],dep[MAXN],son[MAXN],top[MAXN],size[MAXN],fa[MAXN],id[MAXN],dis[MAXN],vis[MAXN];
struct Edge{int u,v,type,id;}e[MAXN<<1];
vector<pii> G[MAXN];
vector<Edge> quq;
vector<int> Ans;
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
struct ufs{
	int fa[MAXN];
	inl void clear(){rep(i,1,n)fa[i]=i;}
	inl int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
}mjy;
inl void dfs1(int u,int father,int deep){
	fa[u]=father,size[u]=1,dep[u]=deep;
	for(auto x:G[u])if(x.fir!=father){
		dfs1(x.fir,u,deep+1);
		if(size[x.fir]>size[son[u]]) son[u]=x.fir;
		size[u]+=size[x.fir],id[x.fir]=x.sec;
	} 
}
inl void dfs2(int u,int topfa){
	top[u]=topfa;
	if(son[u]) dfs2(son[u],topfa);
	for(auto x:G[u]) if(x.fir!=fa[u] && x.fir!=son[u]) dfs2(x.fir,x.fir);
}
inl int lca(int u,int v){
	while(top[u]^top[v])dep[top[u]]<dep[top[v]]?v=fa[top[v]]:u=fa[top[u]];
	return dep[u]<dep[v]?u:v;
}
inl void dfs3(int u){
	vis[u]=1;
	for(auto x:G[u])if(x.fir!=fa[u])dfs3(x.fir),dis[u]+=dis[x.fir];
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,m) read(u),read(v),e[++cnt]={u,v,0,i};
	mjy.clear();
	rep(i,1,m){
		int u=mjy.find(e[i].u),v=mjy.find(e[i].v);
		if(u!=v) mjy.fa[u]=v,G[e[i].u].pb({e[i].v,e[i].id}),G[e[i].v].pb({e[i].u,e[i].id});
		else e[i].type=1;
	}
	rep(i,1,n) if(!size[i]) dfs1(i,i,i),dfs2(i,i);
	rep(i,1,m)
		if(e[i].type && ((dep[e[i].u]+dep[e[i].v]-2*dep[lca(e[i].u,e[i].v)]+1)&1)) 
			quq.pb(e[i]),dis[e[i].u]++,dis[e[i].v]++,dis[lca(e[i].u,e[i].v)]-=2;
		else if(e[i].type)dis[e[i].u]--,dis[e[i].v]--,dis[lca(e[i].u,e[i].v)]+=2;
	if(quq.empty()) {
		printf("%d\n",m);
		rep(i,1,m) printf("%d ",i);
	}else if(quq.size()==1){
		rep(i,1,n) if(!vis[i]) dfs3(i);
		rep(i,1,n)if(dis[i]==1) Ans.pb(id[i]);
		Ans.pb(quq[0].id),sort(all(Ans));
		printf("%d\n",Ans.size());
		for(auto x:Ans) printf("%d ",x);
	}else{
		rep(i,1,n) if(!vis[i]) dfs3(i);
		rep(i,1,n)if(dis[i]==quq.size()) Ans.pb(id[i]);
		sort(all(Ans));
		printf("%d\n",Ans.size());
		for(auto x:Ans) printf("%d ",x);
	}
	return 0;
}