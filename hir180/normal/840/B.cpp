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
int par[300005],ran[300005];
void init(){ for(int i=0;i<300005;i++) par[i] = i; }
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
int n,m,p[300005];
vector<int>edge[300005];
int lca[300005][21],dep[300005];
void dfs(int v,int u){
	lca[v][0] = u;
	if(u==-1) dep[v] = 0;
	else dep[v] = dep[u]+1;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
	}
}
int cnt[300005];
vector<P>ans;
int dfs2(int v,int u){
    int a = cnt[v];
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		int f = dfs2(edge[v][i],v); a+=f;
		if(f%2==1) ans.pb(mp(edge[v][i],v));
	}
	return a;
}
int main(){
	cin >> n >> m;
	int a = 0,b = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(p[i] == 1) a++;
		else if(p[i] == -1) b = i;
	}
	if(a%2 == 1 && b == 0){
		puts("-1"); return 0;
	}
	else if(a%2 == 1) p[b] = 1;
	init();
	map<P,int>M;
	for(int i=0;i<m;i++){
		int a,b; scanf("%d%d",&a,&b);
		if(!same(a,b) && a!=b && M.find(mp(a,b)) ==M.end() && M.find(mp(b,a)) == M.end()){
		    M[mp(a,b)] = i+1; M[mp(b,a)] = i+1;
			unite(a,b);
			edge[a].pb(b);
			edge[b].pb(a);
		}
	}
	vector<int>vec;
	for(int i=1;i<=n;i++) if(p[i] == 1) vec.pb(i);
	dfs(1,-1);
	for(int j=0;j<20;j++){
		for(int i=1;i<=n;i++){
			if(lca[i][j] == -1) lca[i][j+1] = -1;
			else lca[i][j+1] = lca[lca[i][j]][j];
		}
	}
	for(int i=0;i<vec.size();i+=2){
		int a = vec[i],b = vec[i+1];
		cnt[a]++; cnt[b]++;
		if(dep[a] > dep[b]) swap(a,b);
		for(int j=20;j>=0;j--){
			if(!(((dep[b]-dep[a])>>j)&1)) continue;
			b = lca[b][j];
		}
		for(int j=20;j>=0;j--){
			if(lca[a][j]!=lca[b][j]){
				a = lca[a][j];
				b = lca[b][j];
			}
		}
	}
	dfs2(1,-1);
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++){
		if(M.find(ans[i]) != M.end()) printf("%d\n",M[ans[i]]);
		else printf("%d\n",M[mp(ans[i].sc,ans[i].fi)]);
	}
}