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
int n,m,q;
int u[100005],v[100005];
int D[100005],cnt2[100005];
P F;
vector<int>edge[100095];
int sz[100005];
vector<int>cnt[100005];
vector<double>sim[100005],sim2[100005];
void dfs(int v,int u,int d){
	F=max(F,mp(d,v));
	D[v] = max(D[v],d);
	rep(i,edge[v].size()){
		if(edge[v][i]==u) continue;
		dfs(edge[v][i],v,d+1);
	}
}
map<P,double>M;
int main(){
	init();
	scanf("%d%d%d",&n,&m,&q);
	rep(i,m){
		scanf("%d%d",&u[i],&v[i]);
		unite(u[i],v[i]);
		edge[u[i]].pb(v[i]);
		edge[v[i]].pb(u[i]);
	}
	repn(i,n){
		if(find(i) != i)continue;
		F=mp(-1,-1);
		dfs(i,-1,0);
		int V = F.sc;
		F=mp(-1,-1);
		dfs(V,-1,0);
		dfs(F.sc,-1,0);
		sz[i] = F.fi;
		cnt[i].resize(F.fi+1,0);
		sim[i].resize(F.fi+1,0);
		sim2[i].resize(F.fi+1,0);
	}
	repn(i,n){
		cnt[find(i)][D[i]]++;
		cnt2[find(i)]++;
	}
	repn(i,n){
		if(find(i) != i)continue;
		for(int j=sz[i];j>=0;j--){
			if(j!=sz[i]){
				sim[i][j] = sim[i][j+1];
				sim2[i][j] = sim2[i][j+1];
			}
			sim[i][j] += (double)(cnt[i][j])/(double)(cnt2[i]);
			sim2[i][j] += (double)(cnt[i][j])/(double)(cnt2[i]) * (double)(j);
		}
	}
	rep(i,q){
		int a,b; scanf("%d%d",&a,&b);
		a = find(a);b = find(b); if(a>b) swap(a,b);
		if(a==b){ puts("-1"); continue; }
		if(M.find(mp(a,b)) != M.end()) { printf("%.8f\n",M[mp(a,b)]); continue; }
		if(sz[a] > sz[b]) swap(a,b);
		double ans = 0,sum = 0;
		for(int d=sz[a];d>=0;d--){
			sum += (double)(cnt[a][d])/(double)(cnt2[a]) * sim[b][max(0,sz[b]-1-d)];
			ans += (double)(cnt[a][d])/(double)(cnt2[a]) * sim[b][max(0,sz[b]-1-d)] * (double)(d+1);
			ans += (double)(cnt[a][d])/(double)(cnt2[a]) * sim2[b][max(0,sz[b]-1-d)];
		}
		ans += (1.0-sum) * (double)(sz[b]);
		printf("%.8f\n",M[mp(a,b)] = ans);
	}
}