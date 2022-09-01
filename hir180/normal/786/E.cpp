#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
 
int n,m;
int up[20005][18],dep[20005];
vector<int>edge[200005];
 
void dfs(int v,int u){
	if(u == -1) dep[v] = 0; else dep[v] = dep[u]+1;
	up[v][0] = u;
	rep(i,edge[v].size()){
		if(edge[v][i]==u) continue;
		dfs(edge[v][i],v);
	}
}
 
int get_lca(int a,int b){
	if(dep[a] > dep[b]) swap(a,b);
	for(int i=17;i>=0;i--){
		if(dep[b]-dep[a] >= (1<<i)) b = up[b][i];
	}
	if(a==b)return a;
	for(int i=17;i>=0;i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}
template<int SZ> struct Dinic{
struct edge
{
	int to,cap,rev;
};
vector<edge>G[SZ];
bool used[SZ];
int itr[SZ],level[SZ];
void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int>q;
	level[s] = 0; q.push(s);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e = G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to] = level[v]+1;
				q.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f)
{ 
	if(v==t) return f;
	for(int &i=itr[v];i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>0 && level[v] < level[e.to])
		{ 
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0) 
			{ 
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{ 
	int flow=0,f;
	while(bfs(s),level[t]>=0)
	{
		memset(itr,0,sizeof(itr));
		while( (f=dfs(s,t,INF)) > 0){
			flow += f;
		}
	}
	return flow;
}
	bool U[SZ];
    void DFS(int v){
        if(U[v]) return ; U[v] = 1;
        for(int i=0;i<G[v].size();i++){
            if(G[v][i].cap == 0) continue;
            DFS(G[v][i].to);
        }
    }
};
Dinic<400005>kaede;
map<P,int>num;
 
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
		if(a > b) swap(a,b);
		num[mp(a,b)] = i;
	}
	dfs(1,-1);
	rep(j,17) repn(i,n) if(up[i][j]==-1) up[i][j+1] = -1; else up[i][j+1] = up[up[i][j]][j];
	rep(j,18) repn(i,n){
		if(up[i][j] == -1) continue;
		if(j == 0){
			kaede.add_edge(i,400001,1);
		}
		else{
			kaede.add_edge(i+j*n,i+(j-1)*n,n+2);
			kaede.add_edge(i+j*n,up[i][j-1]+(j-1)*n,n+2);
		}
	}
	repn(ii,m){
		int a,b; scanf("%d%d",&a,&b);
		kaede.add_edge(400000,385000+ii,1);
		int c = get_lca(a,b);
		for(int i=17;i>=0;i--){
			if(dep[a]-(1<<i) >= dep[c]){
				kaede.add_edge(385000+ii,i*n+a,n+2);
				a = up[a][i];
			}
		}
		assert(a == c);
		for(int i=17;i>=0;i--){
			if(dep[b]-(1<<i) >= dep[c]){
				kaede.add_edge(385000+ii,i*n+b,n+2);
				b = up[b][i];
			}
		}
		assert(b == c);
	}
	cout << kaede.max_flow(400000,400001) << endl;
	kaede.DFS(400000);
	vector<int>le,ri;
	for(int i=1;i<=m;i++) if(!kaede.U[385000+i]) le.pb(i);
	for(int i=2;i<=n;i++) if(kaede.U[i]){ ri.pb(num[mp(min(i,up[i][0]),max(i,up[i][0]))]+1);}
	printf("%d",le.size()); rep(i,le.size()) printf(" %d",le[i]); puts("");
	printf("%d",ri.size()); rep(i,ri.size()) printf(" %d",ri[i]); puts("");
}