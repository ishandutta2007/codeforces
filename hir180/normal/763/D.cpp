//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>
#include <complex>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
//#define L __int128
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
#define rng(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
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
 
 //https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
	
	size_t operator()(pair<int,int> x)const{
		return operator()(uint64_t(x.first)<<32|x.second);
	}
};
//unordered_set -> dtype, null_type
//unordered_map -> dtype(key), dtype(value)
using namespace __gnu_pbds;
template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

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
//const ll mod = 1000000007;
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
#define _sz 1
ll F[_sz],R[_sz];
void make(){
	F[0] = 1;
	for(int i=1;i<_sz;i++) F[i] = F[i-1]*i%mod;
	R[_sz-1] = modpow(F[_sz-1], mod-2);
	for(int i=_sz-2;i>=0;i--) R[i] = R[i+1] * (i+1) % mod;
}
ll C(int a,int b){
	if(b < 0 || a < b) return 0;
	return F[a]*R[b]%mod*R[a-b]%mod;
}
template<typename F, typename T>
struct segtree{
	int sz;
	vector<T>seg;
	const F f;
	const T e;
	segtree(){}
	segtree(int n, const F f, const T e): f(f), e(e) {
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	void init(int n){
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	//mrg...apply f or not
	void update(int a, T p, bool mrg){
		a += sz-1;
		if(mrg) seg[a] = f(seg[a], p);
		else seg[a] = p;
		while(a){
			a = (a-1)/2;
			seg[a] = f(seg[a*2+1], seg[a*2+2]);
		}
	}
	void make(vector<T>a){
		rep(i, a.size()) seg[i+sz-1] = a[i];
		for(int i=sz-2;i>=0;i--) seg[i] = f(seg[i*2+1], seg[i*2+2]);
	}
	T query(int a, int b){
		a += sz-1, b += sz-1;
		T L = e, R = e;
		while(a <= b){
			if((a&1) == 0) { L = f(L, seg[a++]); }
			if((b&1) == 1) { R = f(seg[b--], R); }
			if(a > b) break;
			a = (a-1) >> 1;
			b = (b-1) >> 1;
		}
		return f(L, R);
	}
};

template<typename F, typename F2, typename T>
struct tree_dp{
	//0-indexed
	//dep small -> big
	int n;
	vc<int>node, dep, up;
	vc<vc<int>>adj;
	//result: same shape of adj, adj: u->v means result: dp[v (parent = u)]
	vc<vc<T>>result;
	vc<T>dat;
	//boss: boss[v] = dp[v (parent = -1)]
	vc<T>boss;
	//F merge function
	//f...subtree vs subtree
	//f2...top vs subtree
	const F f;
	const F2 f2;
	//T data type
	const T e;
	tree_dp(vc<vc<int>>_adj, vc<T>dat, const F f, const F2 f2, const T e): adj(_adj), dat(dat), f(f), f2(f2), e(e) {
		n = adj.size();
		rep(i, n) SORT(adj[i]);
		result.assign(n, vc<T>());
		rep(i, n) result[i].assign(adj[i].size(), e);
		node.assign(n, 0); rep(i, n) node[i] = i;
		dep.assign(n, 0);
		up.assign(n, 0);
		boss.assign(n, e);
		
		auto dfs = [&](int v, int u, auto dfs) -> void{
			up[v] = u;
			if(u == -1) dep[v] = 0; else dep[v] = dep[u] + 1;
			for(auto a:adj[v]) if(a != u) dfs(a, v, dfs);
		};
		dfs(0, -1, dfs);
		sort(node.begin(), node.end(), [&](const int &a, const int &b){
			if(dep[a] != dep[b]) return dep[a] < dep[b];
			return a < b;
		});
		using st = segtree<F, T>;
		auto seg = vc<st>();
		seg.reserve(n);
		rep(i, n){
			seg.pb(st((int)adj[i].size() * 2, f, e));
		}
		for(int _x=n-1;_x>=1;_x--){
			int x = node[_x];
			//solve up[x] -> x
			int p = POSL(adj[x], up[x]);
			auto dp = f2(dat[x], seg[x].query(p+1, p+(int)adj[x].size()-1));
			int q = POSL(adj[up[x]], x);
			result[up[x]][q] = dp;
			seg[up[x]].update(q, dp, false);
			seg[up[x]].update(q + adj[up[x]].size(), dp, false);
		}
		for(int _x=1;_x<n;_x++){
			int x = node[_x];
			//solve x -> up[x]
			int p = POSL(adj[up[x]], x);
			auto dp = f2(dat[up[x]], seg[up[x]].query(p+1, p+(int)adj[up[x]].size()-1));
			int q = POSL(adj[x], up[x]);
			result[x][q] = dp;
			seg[x].update(q, dp, false);
			seg[x].update(q + adj[x].size(), dp, false);
		}
		for(int v=0;v<n;v++) {
			boss[v] = f2(dat[v], seg[v].query(0, (int)adj[v].size()-1));
		}
	}
	T go(int u, int v){
		//u -> v
		int p = POSL(adj[u], v);
		return result[u][p];
	}
	/*
	SAMPLE:
	int n;
	cin >> n;
	vc<vc<int>>adj(n);
	rep(i, n-1){
		int u, v; cin >> u >> v;
		u --; v --;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	using _T = ;
	_T e = ;
	//need initialize
	vc<_T>dat(n, e);
	//f & f2 ... maybe need capture
	
	//merge subtree & subtree
	auto f = [](_T a, _T b) -> _T{
		
	};
	//merge top node & subtree
	auto f2 = [](_T a, _T b) -> _T{
		
	};
	tree_dp<decltype(f), decltype(f2), decltype(e)> fuyuko(adj, dat, f, f2, e);
	*/
};
void solve(){
	int n;
	cin >> n;
	if(n == 1){
		o(1);
		return;
	}
	vc<vc<int>>adj(n);
	rep(i, n-1){
		int u, v; cin >> u >> v;
		u --; v --;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	using _T = unsigned long long;
	hash_table<_T, _T>tb;
	_T e = 0, ins = mt();
	//need initialize
	vc<_T>dat(n, e);
	//f & f2 ... maybe need capture
	
	//merge subtree & subtree
	auto f = [](_T a, _T b) -> _T{
		return a + b;
	};
	//merge top node & subtree
	auto f2 = [&](_T a, _T b) -> _T{
		b ^= ins;
		if(tb.find(b) == tb.end()) tb[b] = mt();
		return tb[b];
	};
	tree_dp<decltype(f), decltype(f2), decltype(e)> fuyuko(adj, dat, f, f2, e);
	hash_table<_T, int>dw;
	for(int i=1;i<n;i++) dw[fuyuko.go(fuyuko.up[i], i)] ++;
	P ans = mp(-1, 0);
	auto dfs = [&](int v, int u, auto dfs) -> void{
		if(ans < mp((int)dw.size(), v)) ans = mp((int)dw.size(), v);
		for(auto a:adj[v]){
			if(a == u) continue;
			int go_down = fuyuko.go(v, a);
			int go_up = fuyuko.go(a, v);
			dw[go_down] --;
			if(dw[go_down] == 0) dw.erase(go_down);
			dw[go_up] ++;
			dfs(a, v, dfs);
			dw[go_up] --;
			if(dw[go_up] == 0) dw.erase(go_up);
			dw[go_down] ++;
		}
	};
	dfs(0, -1, dfs);
	cerr << ans << endl;
	cout << ans.b+1 << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}