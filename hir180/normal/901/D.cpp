#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
int n,m,col[100005];
ll sum[2],num[100005];
bool ex[2];
vector<int>edge[100005];
void dfs(int v,int c){
	if(col[v] != -1) return ;
	col[v] = c;
	sum[c] += num[v];
	rep(i,edge[v].size()){
		if(col[edge[v][i]] == -1) dfs(edge[v][i],1-c);
		else if(col[edge[v][i]] == c){
			ex[c] = 1;
		}
	}
}
P zip[100050];
map<P,ll>val;
int par[100005],ran[100005];
void init(){ for(int i=0;i<100005;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
vector<int>G[100005];
ll DFS(int v,int u){
	ll V = num[v];
	rep(i,G[v].size()){
		if(G[v][i] == u) continue;
		V -= DFS(G[v][i],v);
	}
	if(u == -1) assert(V == 0LL);
	else{
		val[mp(v,u)] = val[mp(u,v)] = V;
	}
	return V;
}
int main(){
	cin>>n>>m;
	repn(i,n) cin>>num[i];
	init();
	rep(i,m){
		int a,b; cin>>a>>b;
		zip[i] = mp(a,b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	memset(col,-1,sizeof(col));
	dfs(1,0);
	if(sum[0] != sum[1] && !ex[0] && !ex[1]){
		puts("NO"); return 0;
	}
	puts("YES");
	repn(i,n){
		rep(j,edge[i].size()){
			if(i > edge[i][j]) continue;
			if(col[i] != col[edge[i][j]]){
        		continue;
			}
			ll hoge = sum[col[i]] - sum[1-col[i]];
			hoge /= 2;
			val[mp(i,edge[i][j])] = val[mp(edge[i][j],i)] = hoge;
			num[i] -= hoge;
			num[edge[i][j]] -= hoge;
			goto nxt;
		}
	}
	nxt:;
	repn(i,n){
		rep(j,edge[i].size()){
			if(i > edge[i][j]) continue;
			if(col[i] != col[edge[i][j]]){
			    int a = i, b = edge[i][j];
			    if(!same(a,b)){
        			G[a].pb(b);
        			G[b].pb(a);
        			unite(a,b);
        		}
        		continue;
			}
		}
	}
	DFS(1,-1);
	for(int i=0;i<m;i++) printf("%lld\n",val[zip[i]]);
}