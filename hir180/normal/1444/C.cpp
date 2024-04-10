//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//#define int long long
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
#define fi first
#define sc second
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 998244353;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
#define SZ 500005

int par[SZ],ran[SZ];
void init(){ for(int i=0;i<SZ;i++) par[i] = i; }
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


struct closed{
	int par[2*SZ],ran[2*SZ];
	void init(int nn){ for(int i=0;i<nn;i++) par[i] = i, ran[i] = 0; }
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
}kaede;

int n, m, k, c[500005], p[500005], num[500005];
vc<int>e[500005];
map<P, vc<P>>G;
bool bad[500005];
void dfs(int v, int c){
	if(num[v] != -1) return; num[v] = c;
	for(auto at:e[v]){
		if(num[at] == -1) dfs(at, c^1);
	}
}
void solve(){
	cin >> n >> m >> k;
	repn(i, n) cin >> c[i];
	init();
	rep(i, m){
		int a, b; cin >> a >> b;
		if(c[a] == c[b]) {
			unite(a, b);
			e[a].pb(b);
			e[b].pb(a);
		}
		else{
			G[mp(min(c[a],c[b]), max(c[a], c[b]))].eb(a, b);
		}
	}
	memset(num, -1, sizeof(num));
	repn(i, n){
		p[i] = find(i);
		dmp(p[i]);
		if(num[i] == -1) dfs(i, 0);
	}
	int C = k;
	repn(i, n){
		assert(num[i] != -1);
		for(auto at:e[i]){
			if(num[i] == num[at]){
				bad[c[i]] = 1;
				dmp(c[i]);
			}
		}
	}
	repn(i, k) if(bad[i]) C--;
	ll ans = 1LL * C * (C-1) / 2;
	
	for(auto at:G){
		int a = at.a.a;
		int b = at.a.b;
		if(bad[a] || bad[b]) continue;
		assert(a < b);
		vc<P>edge = at.b;
		vc<int>L;
		for(auto at2:edge){
			L.pb(p[at2.a]);
			L.pb(p[at2.b]);
		}
		SORT(L); ERASE(L);
		int sz = si(L);
		kaede.init(2 * (sz + 2) );
		for(auto at2:edge){
			int u = POSL(L, p[at2.a]);
			int v = POSL(L, p[at2.b]);
			if(num[at2.a] == num[at2.b]){
				kaede.unite(u, sz+v);
				kaede.unite(v, sz+u);
			}
			else{
				kaede.unite(u, v);
				kaede.unite(u+sz, v+sz);
			}
		}
		rep(i, sz){
			if(kaede.same(i, sz+i)){
				ans --;
				break;
			}
		}
	}
	
	cout << ans << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}