#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
//basis
vector<vector<int>>basis;
map<vector<int>,int>S;
int merge_id[800][800];
int nxt;
void normalize(vector<int>&vec){
	rep(i,vec.size()){
		for(int j=i+1;j<vec.size();j++){
			if(vec[i] > (vec[i]^vec[j])){
				vec[i] ^= vec[j];
			}
		}
	}
}
void gauss(vector<int>&vec){
	SORT(vec); //ERASE(vec);
	for(int j=4;j>=0;j--){
		int pivot = -1;
		rep(i,vec.size()){
			if(vec[i] >= (1<<j) && vec[i] < (2<<j)){
				pivot = i;
				break;
			}
		}
		if(pivot == -1) continue;
		rep(i,vec.size()){
			if(i == pivot) continue;
			if( ((vec[i]>>j)&1) ) vec[i] ^= vec[pivot];
		}
	}
	bool ex = 0;
	vector<int>ret;
	rep(i,vec.size()){
		if(vec[i] == 0) ex = 1;
		else ret.pb(vec[i]);
	}
	if(ex) ret.pb(0);
	sort(ret.begin(),ret.end(),greater<int>());
	vec = ret;
}
void make(int bit,vector<int>vi){
	if(bit == -1){
		normalize(vi);
		if(S.find(vi) == S.end()){
			S[vi] = nxt++;
			basis.pb(vi);
		}
		vi.pb(0);
		if(S.find(vi) == S.end()){
			S[vi] = nxt++;
			basis.pb(vi);
		}
		return;
	}
	for(int lb=(1<<bit);lb<(2<<bit);lb++){
		vi.pb(lb);
		make(bit-1,vi);
		vi.pop_back();
	}
	make(bit-1,vi);
}
struct UF{
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
}kaede,one;
 
ll dp[2][800];
int n,m;
vector<P>edge[100005];
vector<P>adj;
vector<P1>G;
vector<int>B[100005];
vector<int>con[100005],css[100005];
int dist[100005];
 
void makee(int v,int u,int c){
	dist[v] = c;
	rep(i,edge[v].size()){
		int to = edge[v][i].fi;
		int cs = edge[v][i].sc;
		if(u == to) continue;
		makee(to,v,(c^cs));
	}
}
 
int main(){
	vector<int>vi;
	make(4,vi);
	/*cout << S.size() << endl;
	for(auto a:S){
	    for(auto b:a)cout<<b<<" ";
	    cout<<endl;
	}*/
	//748
	//cout<<nxt<<endl;
	
	int kuu;
	rep(i,nxt) if(basis[i].size() == 0) kuu = i;
	//cout<<kuu<<endl;
	
	rep(i,nxt){
		rep(j,nxt){
			vector<int>nw; nw.resize(basis[i].size()+basis[j].size());
			int id = 0;
			for(auto a:basis[i]) nw[id++] = a;
			for(auto a:basis[j]) nw[id++] = a;
			gauss(nw);
			normalize(nw);
			assert(S.find(nw) != S.end());
			merge_id[i][j] = S[nw];
		}
	}
 
	scanf("%d%d",&n,&m);
	kaede.init(); one.init();
	int x = 0; srand((unsigned)time(NULL));
	rep(i,m){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		if(a > b) swap(a,b);
		if(a == 1){
			adj.pb(mp(b,c));
		}
		else{
			if(kaede.same(a,b)){
				G.pb(mp(c,P(a,b)));
			}
			else{
			    kaede.unite(a,b);
			    edge[a].pb(P(b,c));
			    edge[b].pb(P(a,c));
			}
		}
	}
 
	rep(i,adj.size()){
		con[kaede.find(adj[i].fi)] . pb(adj[i].fi);
		css[kaede.find(adj[i].fi)] . pb(adj[i].sc);
		assert(con[kaede.find(adj[i].fi)].size() <= 2);
	}
	for(int i=2;i<=n;i++){
		if(kaede.find(i) != i) continue;
		makee(i,-1,0);
	}
	rep(i,G.size()){
		int a = G[i].sc.fi;
		int b = G[i].sc.sc;
		int cs = G[i].fi;
		//cout << kaede.find(a) << " " << a << " " << b << " " << (dist[a]^dist[b]^cs) << endl;
		B[kaede.find(a)].pb(dist[a]^dist[b]^cs);
	}
	
	repn(i,n) if(B[i].size()){
		gauss(B[i]);
		normalize(B[i]);
	}
	int cur = 0, nxtt = 1;
	dp[0][kuu] = 1;
	repn(i,n){
		if(con[i].empty()) continue;
		rep(j,800) dp[nxtt][j] = 0;
		
		if(con[i].size() == 1){
			assert(S.find(B[i]) != S.end());
			int id = S[B[i]];
			rep(j,nxt){
				if(dp[cur][j] == 0) continue;
				//cut
				dp[nxtt][j] += dp[cur][j];
				//not cut
				dp[nxtt][merge_id[j][id]] += dp[cur][j];
			}
		}
		else{
			assert(con[i].size() == 2);
			assert(S.find(B[i]) != S.end());
			int id = S[B[i]];
			rep(j,nxt){
				if(dp[cur][j] == 0) continue;
				//double cut
				dp[nxtt][j] += dp[cur][j];
				//one cut
				dp[nxtt][merge_id[j][id]] += dp[cur][j]*2LL;
			}
			//no cut
			int nw = (css[i][0]^css[i][1]^dist[con[i][0]]^dist[con[i][1]]);
			//cout<<nw<<endl;
			B[i].pb(nw);
			gauss(B[i]);
			normalize(B[i]);
			
			assert(S.find(B[i]) != S.end());
			id = S[B[i]];
			rep(j,nxt){
				if(dp[cur][j] == 0) continue;
				//no cut
				dp[nxtt][merge_id[j][id]] += dp[cur][j];
			}
		}
		swap(cur,nxtt);
		rep(j,nxt) dp[cur][j] %= mod;
	}
	ll ans = 0;
	rep(j,nxt){
		rep(k,basis[j].size()) if(basis[j][k] == 0) goto fail;
		ans += dp[cur][j]; fail:;
	}
	printf("%lld\n",(ans%mod+mod)%mod);
}