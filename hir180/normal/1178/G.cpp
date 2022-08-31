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
mt19937_64 mt(0);//chrono::steady_clock::now().time_since_epoch().count());
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
//kinetic tournament

//query
//l <= i <= r and x : b_i += a_i * x
//l <= i <= r : calc min(b_i)
//i: set a_i and b_i

template<typename T>
struct kinetic_tournament{
	int sz;
	vector<T>seg;
	vector<T>a, b, min_ch, lazy;
	const T e;
	kinetic_tournament(int n, const T e): e(e) {
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
		//think twice about how to initialize
		a.assign(2*sz, 0);
		b.assign(2*sz, e);
		min_ch.assign(2*sz, (T)3e18);
		lazy.assign(2*sz, 0);
	}
	/*void init(int n){
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}*/
	void push(int k){
		repn(p, 2){
			min_ch[k*2+p] -= lazy[k];
			lazy[k*2+p] += lazy[k];
			b[k*2+p] += a[k*2+p] * lazy[k];
		}
		lazy[k] = 0;
	}
	void pull(int k){
		T a1 = a[k*2+1], b1 = b[k*2+1];
		T a2 = a[k*2+2], b2 = b[k*2+2];
		min_ch[k] = min(min_ch[k*2+1], min_ch[k*2+2]);
		
		if(min(b1, b2) == b1){
			a[k] = a1, b[k] = b1;
			if(a1 > a2){
				int need = (b2-b1) / (a1-a2) + 1;
				min_ch[k] = min(min_ch[k], need);
			}
		}
		else{
			a[k] = a2, b[k] = b2;
			if(a1 < a2){
				int need = (b1-b2) / (a2-a1) + 1;
				min_ch[k] = min(min_ch[k], need);
			}
		}
	}
	//point
	void update(int i, int aa, int bb, int k, int l, int r){
		if(l == r){
			seg[k] = bb;
			a[k] = aa;
			b[k] = bb;
			return;
		}
		push(k);
		if(l <= i and i <= (l+r)/2) update(i, aa, bb, k*2+1, l, (l+r)/2);
		else update(i, aa, bb, k*2+2, 1+(l+r)/2, r);
		pull(k);
	}
	void update(int i, int aa, int bb){ update(i, aa, bb, 0, 0, sz-1); }
	//range add
	//lb<=i<=ub: b_i += a[i] * v
	void add(int lb, int ub, int v, int k, int l, int r){
		if(ub < l or r < lb or lb > ub) return;
		if(lb <= l and r <= ub and min_ch[k] > v){
			lazy[k] += v;
			min_ch[k] -= v;
			b[k] += a[k] * v;
			return;
		}
		if(lazy[k]) push(k);
		add(lb, ub, v, k*2+1, l, (l+r)/2);
		add(lb, ub, v, k*2+2, (l+r)/2+1, r);
		pull(k);
	}
	void add(int lb, int ub, int v){ add(lb, ub, v, 0, 0, sz-1); }
	//calc min(b_i)
	//lb<=i<=ub
	T query(int lb, int ub, int k, int l, int r){
		if(ub < l or r < lb or lb > ub) return e;
		if(lb <= l and r <= ub){
			return b[k];
		}
		if(lazy[k]) push(k);
		return min(query(lb, ub, k*2+1, l, (l+r)/2), query(lb, ub, k*2+2, (l+r)/2+1, r));
	}
	T query(int lb, int ub){ return query(lb, ub, 0, 0, sz-1); }
};
//e
/*int e = INF;
kinetic_tournament<decltype(e)>seg((1<<), e);*/
int n, q;
vc<int>edge[200005];
int sa[200005], sb[200005];
int in[200005], out[200005], id;
void dfs(int v, int u, int upa, int upb){
	upa += sa[v]; sa[v] = upa;
	upb += sb[v]; sb[v] = upb;
	in[v] = id ++;
	for(auto a:edge[v]){
		if(a == u) continue;
		dfs(a, v, upa, upb);
	}
	out[v] = id - 1;
}
void solve(){
	cin >> n >> q;
	rep(i, n-1){
		int p; cin >> p;
		edge[p].pb(i+2);
	}
	repn(i, n) cin >> sa[i];
	repn(i, n) cin >> sb[i];
	dfs(1, -1, 0, 0);
	repn(i, n) sb[i] = abs(sb[i]);
	int e = 1e18;
	kinetic_tournament<decltype(e)>seg(n*2, e);
	repn(i, n) {
		seg.update(in[i]*2, sb[i], sa[i]*sb[i]);
		seg.update(in[i]*2+1, -sb[i], -sa[i]*sb[i]);
	}
	rep(i, q){
		int t; cin >> t;
		if(t == 1){
			int v, x; cin >> v >> x;
			seg.add(in[v]*2, out[v]*2+1, x);
		}
		else{
			int v; cin >> v;
			o(-seg.query(in[v]*2, out[v]*2+1));
		}
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}