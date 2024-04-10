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

struct XOR{
	vector<pair<int,ll>>t;
	void init(vector<ll>a){
		t.clear();
		vector<ll>vec = a;
		int cur = 0;
		for(int mask=60;mask>=0;mask--){
			bool found = 0;
			for(int j=cur;j<vec.size();j++){
				if(((vec[j]>>mask)&1LL)){
					swap(vec[cur],vec[j]);
					found = 1;
					break;
				}
			}
			if(!found) continue;
			for(int j=cur+1;j<vec.size();j++){
				if(((vec[j]>>mask)&1LL)){
					vec[j] ^= vec[cur];
				}
			}
			cur++;
		}
		if(vec.size() > 100) vec.resize(100);
		while(vec.size() && vec[vec.size()-1] == 0) vec.pop_back();
		for(int i=0;i<vec.size();i++){
			int up = -1;
			for(int j=60;j>=0;j--){
				if(((vec[i]>>j)&1LL)){
					up = j;
					break;
				}
			}
			t.pb(mp(up,vec[i]));
		}
	}
}kaede[100005];

struct uf{
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
}shiki;

int n,m;
vector<pair<int,ll>>edge[100005];
vector<pair<P,ll>>A,add[100005];
vector<int>id[100005];
ll ans,rui[100005];
void dfs(int v,int u,ll r){
	rui[v] = r;
	rep(i,edge[v].size()){
		if(edge[v][i].fi == u) continue;
		dfs(edge[v][i].fi,v,r^edge[v][i].sc);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	shiki.init();
	rep(i,m){
		int a,b; ll c; scanf("%d%d%lld",&a,&b,&c);
		
		if(shiki.same(a,b) == false){
			shiki.unite(a,b);
			edge[a].pb(mp(b,c));
			edge[b].pb(mp(a,c));
		}
		else A.pb(mp(mp(a,b),c));
	}
	rep(i,A.size()){ add[shiki.find(A[i].fi.fi)].pb(A[i]); }
	repn(i,n){
		id[shiki.find(i)].pb(i);
		if(shiki.find(i) != i) continue;
		dfs(i,-1,0);
	}
	
	repn(i,n){
		if(shiki.find(i) != i) continue;
		vector<ll>vc;
		rep(x,add[i].size()){
			int u = add[i][x].fi.fi;
			int v = add[i][x].fi.sc;
			ll c = add[i][x].sc;
			c ^= rui[u]^rui[v];
			vc.pb(c);
		}
		kaede[i].init(vc);
		
		rep(j,60){
			bool ex = 0;
			for(auto za:kaede[i].t){
				if((((za.sc)>>j)&1)) { ex = 1; break; }
			}
			int sz = kaede[i].t.size();
			
			ll a,b;
			if(ex) a = b = (1LL<<(sz-1));
			else {
				a = 0;
				b = (1LL<<sz);
			}
			
			int o = 0, z = 0;
			rep(k,id[i].size()){
				ll cs = rui[id[i][k]];
				if(((cs>>j)&1)) o++;
				else z++;
			}
			ll c = 1LL*o*z, d = 1LL*o*(o-1)/2+1LL*z*(z-1)/2;
			a%=mod; b%=mod; c%=mod; d%=mod;
			ans += (1LL<<j)%mod * (a%mod*d%mod+b%mod*c%mod) % mod;
		}
	}
	
	cout << (ans%mod+mod)%mod << endl;
}