#include<bits/stdc++.h>
using namespace std;
#define N 600010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,k,Q,c[N];
vector<pair<int,int> > G[N];
vector<int> H[N];
ll dis[N],val[N];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void Dijkstra(){
	static int vis[N];
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:G[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				c[v]=c[u];
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
struct Union_Set{
	int f[N];
	void init(int n){for(int i=1;i<=n;++i)f[i]=i;}
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
}S;
int tot,rt;
struct Link{
	int x,y;
	ll w;
	friend bool operator < (const Link &a,const Link &b){
		return a.w<b.w;
	}
}L[N];
int top[N],son[N],siz[N],f[N],dep[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:H[u]){
		dep[v]=dep[u]+1;
		f[v]=u;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:H[u]){
		if(v==son[u])continue;
		dfs2(v,v);
	}
}
inline int LCA(int x,int y){
	while(top[x]^top[y]){
		while(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;	
}
int main(){
	n=read(),m=read(),k=read(),Q=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=k;++i){
		q.push(make_pair(0LL,i));
		dis[i]=0,c[i]=i;
	}
	Dijkstra();
	for(int u=1;u<=n;++u){
		for(auto [v,w]:G[u]){
			if(v>u){
				L[++tot]={c[u],c[v],dis[u]+dis[v]+w};	
			}
		}
	}
	S.init(n<<1);
	sort(L+1,L+tot+1);
	rt=n;
	for(int i=1;i<=tot;++i){
		int fx=S.getf(L[i].x),fy=S.getf(L[i].y);
		if(fx==fy)continue;
		val[++rt]=L[i].w;
		S.f[fx]=S.f[fy]=rt;
		H[rt].push_back(fx);
		H[rt].push_back(fy);
	}
	dfs1(rt);
	dfs2(rt,rt);
	while(Q--){
		int x=read(),y=read();
		printf("%lld\n",val[LCA(x,y)]);
	}
	return 0;
}