#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=2e5+5;
int T,n,tot,tp,dep[N],fa[N],sz[N],dfn[N],son[N],top[N],sp[N],vis[N],st[N];
struct Dijk{
	int d,i,x,r;
	Dijk(){}
	Dijk(int _d,int _i,int _x){
		d=_d,i=_i,x=_x;r=d?(d-1)/sp[x]:-1;
	}
	bool operator<(const Dijk&o)const{
		return r==o.r?i<o.i:r<o.r;
	}
}dis[N];
struct Node{
	int id;Dijk d;
	bool operator<(const Node&o)const{
		return d.r==o.d.r?d.i>o.d.i:d.r>o.d.r;
	}
};
vector<int>G[N],g[N],q,S,R,p,Q;
inline void rd(int &x){
    x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-f;
    do x=x*10+(48^c);while(isdigit(c=getchar()));x*=f;
}
inline void dfs(int x,int F){
	sz[x]=1,dep[x]=dep[F]+1,fa[x]=F,dfn[x]=++tot;
	for(auto y:G[x])if(y^F){
		dfs(y,x),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
inline void dfs1(int x,int tp){
	top[x]=tp;
	if(son[x])dfs1(son[x],tp);
	for(auto y:G[x])if(y!=fa[x]&&y!=son[x])dfs1(y,y);
}
inline int lca(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
inline int Dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
inline void dijkstra(){
	priority_queue<Node>qu;
	for(auto x:R)dis[x].r=dis[x].i=n,vis[x]=0;
	int sz=S.size();
	rep(i,0,sz-1)
		dis[S[i]]=(Dijk){0,i+1,S[i]},qu.push({S[i],dis[S[i]]});
	while(!qu.empty()){
		Node now=qu.top();qu.pop();int x=now.id;
		if(vis[x])continue;vis[x]=1;
		for(auto y:g[x]){
			Dijk nw=Dijk(dis[x].d+Dis(x,y),dis[x].i,dis[x].x);
			if(nw<dis[y])dis[y]=nw,qu.push({y,dis[y]});
		}
	}
	for(auto x:Q)printf("%d ",dis[x].i);puts("");
}
inline void add_edge(int x,int y){g[x].eb(y),g[y].eb(x);}
int main(){
	rd(n);
	rep(i,2,n){
		int u,v;rd(u),rd(v);
		G[u].eb(v),G[v].eb(u);
	}
	dfs(1,0),dfs1(1,1);
	for(rd(T);T--;){
		int k,m;rd(k),rd(m);
		p.clear(),q.clear(),Q.clear(),S.clear(),R.clear();
		rep(i,1,k){int x,y;rd(x),rd(y);p.eb(x),S.eb(x),sp[x]=y;}
		rep(i,1,m){int x;rd(x);p.eb(x),Q.eb(x);}
		sort(p.begin(),p.end(),[&](int x,int y){return dfn[x]<dfn[y];});
		int sz=p.size();
		rep(i,0,sz-2)if(p[i]^p[i+1])q.eb(p[i]);q.eb(p[sz-1]);
		st[tp=1]=1,R.eb(1);
		for(auto x:q){
			if(x==1)continue;
			int l=lca(x,st[tp]);
			if(l^st[tp]){
				while(dfn[l]<dfn[st[tp-1]])
					add_edge(st[tp],st[tp-1]),--tp;
				add_edge(st[tp],l);
				if(l==st[tp-1])--tp;else st[tp]=l,R.eb(l);
			}
			st[++tp]=x,R.eb(x);
		}
		rep(i,1,tp-1)add_edge(st[i],st[i+1]);
		dijkstra();
		for(auto x:R)g[x].clear();
		for(auto x:S)sp[x]=0;
	}
	return 0;
}