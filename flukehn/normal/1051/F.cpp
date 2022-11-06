#include<bits/stdc++.h>
using namespace std;
typedef long long L;
typedef pair<int,int> pa;
#define x first
#define y second
#define pb push_back
const int N=1e5+11;
int n,m;
vector<pa> g[N],gg[N];
//
L D[N];
int fa[N],dep[N],sz[N],sc[N];
void dfs(int x,int f){
	//cerr<<x<<endl;
	fa[x]=f;
	dep[x]=dep[f]+1;
	sz[x]=1;
	for(auto a:g[x])
		if(a.x!=f){
			D[a.x]=D[x]+a.y;
			dfs(a.x,x);
			sz[x]+=sz[a.x];
			if(sz[a.x]>sz[sc[x]])
				sc[x]=a.x;
		}
}
int rf[N];
void dfs2(int x,int f){
	rf[x]=sc[f]==x?rf[f]:x;
	for(auto a:g[x])
		if(a.x!=f){
			dfs2(a.x,x);
		}
}
int lca(int x,int y){
	while(rf[x]^rf[y]){
		if(dep[rf[x]]<dep[rf[y]])swap(x,y);
		x=fa[rf[x]];
	}
	return dep[x]<dep[y]?x:y;
}
//
template<typename T>
bool upmn(T &x,T y){return x>y?x=y,1:0;}
void dij(int x,L *f){
	priority_queue<pair<L,int> ,vector<pair<L,int> > ,greater<pair<L,int> > > q;
	int i;
	for(i=1;i<=n;++i)
		f[i]=~0uLL>>2;
	f[x]=0;
	q.push({0,x});
	while(!q.empty()){
		pair<L,int> a=q.top();
		q.pop();
		if(a.x>f[a.y])continue;
		for(auto b:g[a.y]){
			if(upmn(f[b.x],a.x+b.y))
				q.push({f[b.x],b.x});
		}
		for(auto b:gg[a.y]){
			if(upmn(f[b.x],a.x+b.y))
				q.push({f[b.x],b.x});
		}
	}
}
int p[44],t;
L f[44][N];
//dsu
int du[N];
int Fa(int x){
	return du[x]!=x
	?du[x]=Fa(du[x]):x;
}
//
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	cin>>n>>m;
	int i,x,y,d;
	for(i=1;i<=n;++i)du[i]=i;
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&d);
		if(Fa(x)==Fa(y)){
			gg[x].pb({y,d});
			gg[y].pb({x,d});
			continue;
		}
		g[x].pb({y,d});
		g[y].pb({x,d});
		du[du[x]]=du[y];
	}
	dfs(1,0);
	dfs2(1,0);
	for(i=1;i<=n;++i)
		if(gg[i].size())
			p[++t]=i;
	//cerr<<"ok\n";
	for(i=1;i<=t;++i)
		dij(p[i],f[i]);
	int q;
	cin>>q;
	while(q--){
		scanf("%d%d",&x,&y);
		L p=D[x]+D[y]-2*D[lca(x,y)];
		for(i=1;i<=t;++i)
			upmn(p,f[i][x]+f[i][y]);
		//cerr<<p<<endl;
		printf("%I64d\n",p);
	}
}