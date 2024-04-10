#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n;
#define Maxn 200010
#define cout cerr
#define FR first
#define SE second
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

namespace hh{
	int sum,rt;
	pll dist[Maxn];int all[Maxn];
	int dis[Maxn][20],dep[Maxn];
	int anc[Maxn],siz[Maxn],mx[Maxn];bool vis[Maxn];
	void getsiz(int u,int f){
		siz[u]=1;
		for(int i=head[u];i;i=nxt[i])
			if(!vis[v[i]]&&v[i]!=f){
				getsiz(v[i],u);
				siz[u]+=siz[v[i]];
			}
	}	
	void findroot(int u,int f){
		mx[u]=0;
		for(int i=head[u];i;i=nxt[i])
			if(v[i]!=f&&!vis[v[i]]){
				findroot(v[i],u);
				mx[u]=max(mx[u],siz[v[i]]);
			}
		mx[u]=max(mx[u],sum-siz[u]);
		if(!rt||mx[u]<mx[rt])rt=u;
	}
	void dfs(int u,int f,int D){
		for(int i=head[u];i;i=nxt[i])
			if(v[i]!=f&&!vis[v[i]]){
				dis[v[i]][D]=dis[u][D]+1;
				dfs(v[i],u,D);
			}
	}
	void solve(int u){
		vis[u]=true;
		dfs(u,0,dep[u]);
		for(int i=head[u];i;i=nxt[i])
			if(!vis[v[i]]){
				getsiz(v[i],u);
				sum=siz[v[i]];rt=0;
				findroot(v[i],u);
				anc[rt]=u;dep[rt]=dep[u]+1;
				solve(rt);
			}
	}
	void update(int u,int ad){
		int D=dep[u],y=u;all[u]+=ad;
		while(anc[u]){
			int x=anc[u];
			dist[x].FR+=dis[y][D-1]*ad;dist[u].SE+=dis[y][D-1]*ad;
			all[x]+=ad;
			u=x;
			D--;
		}
	}
	ll query(int u){
		ll res=dist[u].FR;int y=u,D=dep[u];
		while(anc[u]){
			int x=anc[u];
			res+=dist[x].FR-dist[u].SE;
			res+=1ll*(all[x]-all[u])*dis[y][D-1];
			u=x;
			D--;
		}
		return res;
	}
	void Build(){
		getsiz(1,0);
		rt=0;sum=2*n-1;
		findroot(1,0);
		solve(rt);
	}
}

int fa[Maxn][18],dep[Maxn];
void go_up(int &k,int d){
	per(i,17,0)
		if(d&(1<<i))k=fa[k][i];
}
int LCA(int x,int y){
	if(dep[x]>dep[y])go_up(x,dep[x]-dep[y]);
	if(dep[x]<dep[y])go_up(y,dep[y]-dep[x]);
	if(x==y)return x;
	per(i,17,0)
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
int dis(int x,int y){
	int lca=LCA(x,y);
	return dep[x]+dep[y]-2*dep[lca];
}
void dfs(int u,int f){
	rep(i,1,17)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^f){
			fa[v[i]][0]=u;
			dep[v[i]]=dep[u]+1;
			dfs(v[i],u);
		}
}

pii Add(pii x,int u){
	int lca=LCA(x.FR,u),d=dep[x.FR]+dep[u]-2*dep[lca];
	if(d<=x.SE)return x;
	pii res;res.SE=(x.SE+d)/2;
	if(dep[u]-dep[lca]>=res.SE)go_up(res.FR=u,res.SE);
	else go_up(res.FR=x.FR,d-res.SE);
	return res;
}
bool cv(pii t1,pii t2){
	return t1.SE>=t2.SE+dis(t1.FR,t2.FR);
}
bool equal(pii t1,pii t2){return t1.FR==t2.FR&&t1.SE==t2.SE;}

pii h1[Maxn],h2[Maxn];int l1,l2;
ll Ans=0;
void solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	ll c1=0,c2=0;
	l1=0;per(i,mid,l){l1++;if(l1==1)h1[l1]=pii(i,0);else h1[l1]=Add(h1[l1-1],i);}
	l2=0;rep(i,mid+1,r){l2++;if(l2==1)h2[l2]=pii(i,0);else h2[l2]=Add(h2[l2-1],i);c2+=h2[l2].SE;}
	int L=0,R=1;
	rep(i,1,l1){
		while(R<=l2&&(!cv(h2[R],h1[i]))){
			hh::update(h2[R].FR,1);c2-=h2[R].SE;c1+=h2[R].SE;
			R++;
		}
		while(L+1<=l2&&(cv(h1[i],h2[L+1])&&(!equal(h1[i],h2[L+1])))){
			L++;
			hh::update(h2[L].FR,-1);
			c1-=h2[L].SE;
		}
		Ans+=1ll*(R-L-1)*h1[i].SE;Ans+=2*c2;Ans+=c1;
		Ans+=2ll*L*h1[i].SE;
		Ans+=hh::query(h1[i].FR);
	}
	while(L<R-1){
		L++;
		hh::update(h2[L].FR,-1);
	}
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);
	int s,e;
	rep(i,1,n-1){
		rd(s);rd(e);
		add_edge(s,i+n);add_edge(i+n,e);
	}
	hh::Build();
	dfs(1,0);
	solve(1,n);Ans/=2;
	printf("%lld\n",Ans);
	return 0;
}