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
//#define all(x) x.begin(),x.end()
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
mt19937_64 mt(0); //chrono::steady_clock::now().time_since_epoch().count());
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
const int MAXN = 700;
struct mf{
	// 1-based Vertex index
	int vis[MAXN], par[MAXN], orig[MAXN], match[MAXN], aux[MAXN], t, N;
	vector<int> conn[MAXN];
	queue<int> Q;
	int tmp = 0;
	void add_edge(int u, int v) {
		conn[u].push_back(v); conn[v].push_back(u);
		tmp ++;
	}
	void init(int n) {
		N = n; t = 0;
		for(int i=0; i<=n; ++i) {
			conn[i].clear();
			match[i] = aux[i] = par[i] = 0;
		}
	}
	void augment(int u, int v) {
		int pv = v, nv;
		do {
			pv = par[v]; nv = match[pv];
			match[v] = pv; match[pv] = v;
			v = nv;
		} while(u != pv);
	}
	int lca(int v, int w) {
		++t;
		while(true) {
			if(v) {
				if(aux[v] == t) return v; aux[v] = t;
				v = orig[par[match[v]]];
			}
			swap(v, w);
		}
	}
	void blossom(int v, int w, int a) {
		while(orig[v] != a) {
			par[v] = w; w = match[v];
			if(vis[w] == 1) Q.push(w), vis[w] = 0;
			orig[v] = orig[w] = a;
			v = par[w];
		}
	}
	bool bfs(int u) {
		fill(vis+1, vis+1+N, -1); iota(orig + 1, orig + N + 1, 1);
		Q = queue<int> (); Q.push(u); vis[u] = 0;
		while(!Q.empty()) {
			int v = Q.front(); Q.pop();
			for(int x: conn[v]) {
				if(vis[x] == -1) {
					par[x] = v; vis[x] = 1;
					if(!match[x]) return augment(u, x), true;
					Q.push(match[x]); vis[match[x]] = 0;
				}
				else if(vis[x] == 0 && orig[v] != orig[x]) {
					int a = lca(orig[v], orig[x]);
					blossom(x, v, a); blossom(v, x, a);
				}
			}
		}
		return false;
	}
	int Match() {
		int ans = 0;
		// find random matching (not necessary, constant improvement)
		vector<int> V(N-1); iota(V.begin(), V.end(), 1);
		shuffle(V.begin(), V.end(), mt19937(61471));
		for(auto x: V) if(!match[x]){
			for(auto y: conn[x]) if(!match[y]) {
				match[x] = y, match[y] = x;
				++ans; break;
			}
		}
		for(int i=1; i<=N; ++i) if(!match[i] && bfs(i)) ++ans;
		return ans;
	}
}mf;
#define sz 605
int par[sz],ran[sz];
void init(){ for(int i=0;i<sz;i++) par[i] = i, ran[i] = 0; }
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
int n, a[300005];
bool ok[605];

hash_table<P, int>ht;
void solve(){
	cin >> n;
	repn(i, n){
		cin >> a[i];
		if(a[i] and a[i] == a[i-1]) ok[a[i]] = 1;
	}
	init();
	vc<P2>ee;
	vc<P2>oe;
	vc<int>add;
	vc<P>edge[605];
	repn(i, n){
		if(a[i]) continue;
		int beg = i;
		int en = i;
		while(en <= n and a[en] == 0) en ++;
		//[beg, en)
		if(beg%2 == en%2){
			//even
			if(beg > 1 and en <= n and a[beg-1] != a[en] and !ok[a[beg-1]] and !ok[a[en]]){
				ee.eb(mp(a[beg-1], a[en]), mp(beg, en-1));
			}
		}
		else{
			//odd
			int le = 0; if(beg > 1 and !ok[a[beg-1]]) le = a[beg-1];
			int ri = 0; if(en <= n and !ok[a[en]]) ri = a[en];
			
			if(max(le, ri) > 0){
				if(le == 0) le = ri;
				if(ri == 0) ri = le;
				oe.eb(mp(le, ri), mp(beg, en-1));
				if(!same(le, ri)) {
					ht[mp(le, ri)] = oe.size()-1;
					ht[mp(ri, le)] = oe.size()-1;
					unite(le, ri);
					edge[le].eb(ri, oe.size()-1);
					edge[ri].eb(le, oe.size()-1);
				}
				else add.eb(oe.size());
			}
		}
		i = en-1;
	}
	vc<int>all(605);
	rep(i, 605) all[i] = -1;
	
	for(auto xx:add) {
		int u = oe[xx-1].a.a;
		all[find(u)] = xx-1;
	}
	hash_table<P, null_type>used;
	mf.init(603);
	rep(x, ee.size()){
		auto uv = ee[x];
		int u = uv.a.a;
		int v = uv.a.b;
		if(!same(u, v) and all[find(u)] == -1 and all[find(v)] == -1 and used.find(mp(find(u), find(v))) == used.end()){
			ht[mp(u, v)] = x;
			ht[mp(v, u)] = x;
			mf.add_edge(find(u), find(v));
			used.insert(mp(find(u), find(v)));
			used.insert(mp(find(v), find(u)));
		}
	}
	mf.Match();
	used.clear();
	vc<int>spe(605, -1);
	rep(x, ee.size()){
		auto uv = ee[x];
		int u = uv.a.a;
		int v = uv.a.b;
		
		if(mf.match[find(u)] == find(v)){
			if(used.find(mp(find(u), find(v))) != used.end()) continue;
			used.insert(mp(find(u), find(v)));
			used.insert(mp(find(v), find(u)));
			a[uv.b.a] = a[uv.b.a-1];
			a[uv.b.b] = a[uv.b.b+1];
			spe[find(u)] = u;
			spe[find(v)] = v;
		}
	}
	auto make = [&](int v, int u, auto make) -> void{
		for(auto aa:edge[v]){
			if(aa.a == u) continue;
			int id = aa.b;
			int u = oe[id].a.a, vv = oe[id].a.b;
			int le = oe[id].b.a, ri = oe[id].b.b;
			
			if(le > 1 and a[le-1] == aa.a) a[le] = aa.a;
			else{
				assert(ri < n and a[ri+1] == aa.a);
				a[ri] = aa.a;
			}
			make(aa.a, v, make);
		}
	};
	repn(i, 600){
		if(find(i) != i) continue;
		int root = i;
		if(all[i] != -1){
			//set i to oe[all[i]]
			int u = oe[all[i]].a.a, v = oe[all[i]].a.b;
			int le = oe[all[i]].b.a, ri = oe[all[i]].b.b;
			if(le > 1 and a[le-1] == u){
				a[le] = u;
			}
			else{
				assert(ri < n and a[ri+1] == u);
				a[ri] = u;
			}
			root = oe[all[i]].a.a;
		}
		else if(spe[i] != -1){
			root = spe[i];
		}
		
		make(root, -1, make);
	}

	vc<int>zan;
	bool ex[605] = {};
	repn(i, n){
		ex[a[i]] = 1;
	}
	repn(i, n) if(i > 600 or !ex[i]) zan.pb(i);

	int nxt = 0;
	repn(i, n){
		if(a[i]) continue;
		if(i < n and a[i+1] == 0){
			a[i] = zan[nxt];
			a[i+1] = zan[nxt];
		}
		else{
			a[i] = zan[nxt];
		}
		nxt ++;
	}
	repn(i, n) cout << a[i] << " "; cout << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}