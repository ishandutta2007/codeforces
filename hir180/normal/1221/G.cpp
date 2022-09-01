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
struct meets_in_middle{
	#define SZ 20
	int sub[(1<<SZ)];
	bool ok[(1<<SZ)];
	int cn[(1<<SZ)];
	int n;
	ll solve(vector<vector<int>>g){
		n = g.size();
		int m = n/2;
		sub[0] = 1;
		repn(i,(1<<m)-1){
			vector<int>vi;
			rep(j,m) if(((i>>j)&1)) vi.pb(j);
			if(sub[i-(1<<vi[0])] == 0) continue;
			for(int j=1;j<vi.size();j++) if(g[vi[0]][vi[j]]) goto fail;
			sub[i] = 1; fail:;
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<(1<<m);j++){
				if(((j>>i)&1)) sub[j] += sub[j^(1<<i)];
			}
		}
		ok[0] = 1;
		repn(i,(1<<(n-m))-1){
			vector<int>vi;
			rep(j,n-m) if(((i>>j)&1)) vi.pb(j);
			if(ok[i-(1<<vi[0])] == 0) continue;
			for(int j=1;j<vi.size();j++) if(g[vi[0]+m][vi[j]+m]) goto fail2;
			ok[i] = 1; fail2:;
		}
		rep(i,n-m){
			rep(j,m) if(g[j][m+i]) cn[(1<<i)] |= (1<<j);
		}
		rep(i,(1<<(n-m))){
			if(__builtin_popcount(i) <= 1) continue;
			rep(j,n-m){
				if(((i>>j)&1)) cn[i] |= cn[i-(1<<j)];
			}
		}
		ll ret = 0;
		rep(i,(1<<(n-m))){
			if(!ok[i]) continue;
			int good = (1<<m)-1-cn[i];
			ret += sub[good];
		}
		return ret;
	}
}solver;
int n,m;
bool ex[45][45];
int par[45],ran[45];
void init(){ for(int i=0;i<45;i++) par[i] = i; }
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
vector<int>ls[45];
int col[45];
void dfs(int v,int c){
	if(col[v] != -1) return; col[v] = c;
	repn(i,n){
		if(ex[i][v] && col[i] == -1) dfs(i,1-c);
	}
}
int main(){ 
    cin>>n>>m; init(); int cur = n;
    rep(i,m){
        int a,b; cin >> a >> b; a--; b--;
        ex[a][b] = ex[b][a] = 1; if(!same(a,b)) { cur--; unite(a,b);}
    }
    rep(i,n) ls[find(i)].pb(i);
    vector<vector<int>>V;
    rep(i,n){
        vector<int>vi;
        rep(j,n) vi.pb(ex[i][j]);
        V.pb(vi);
    }
    ll ans = (1LL<<n);
    //not exist 0,2
    //0=0
    ans -= 2LL*solver.solve(V);
    //not exist 1
    //0/1
    ans -= 1LL<<cur; 
    //not exist 0&1
    //not exist 1&2
    //>=20 1
    ll C = 1; rep(i,n) if(ls[i].size() == 1) C<<=1;
    ans += 2LL*C;;
    //not exist 0&2
    //
	memset(col,-1,sizeof(col));
	ll D = 1;
	rep(i,n) if(col[i]==-1) {dfs(i,0);D<<=1;}
	rep(i,n)rep(j,n) if(ex[i][j]&&col[i]==col[j]) D = 0;
	ans += D; 
	//not exist 0&1&2
	//
	ans -= (m==0?(1LL<<n):0);
	cout << ans <<endl;

}