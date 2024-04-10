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
//!!not a multiset!!
//find_by_order(k) -> *iterator* of k-th(0-based) element
//order_of_key(k) -> index of lower_bound(k)
using namespace __gnu_pbds;
template<class T>
using os=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

os<P1>SS[100005];

void solve(){
	int n, m; cin >> n >> m;
	vc<P1>all;
	vc<pair<int, P1>>query;
	hash_table<P, int>zan;
	rep(i, m){
		int a, b, c; cin >> a >> b >> c;
		if(a > b) swap(a, b);
		zan[mp(a, b)] = c;
		all.eb(c, mp(a, b));
		query.eb(1, mp(c, mp(a, b)));
	}
	int q; cin >> q;
	rep(i, q){
		int t; cin >> t;
		if(t == 0){
			int a, b; cin >> a >> b; if(a > b) swap(a, b);
			query.eb(0, mp(zan[mp(a, b)], mp(a, b)));
		}
		else{
			int a, b, c; cin >> a >> b >> c;
			if(a > b) swap(a, b);
			all.eb(c, mp(a, b));
			query.eb(1, mp(c, mp(a, b)));
			zan[mp(a, b)] = c;
		}
	}
	rep(i, m){
		auto z = query[i].b;
		SS[z.b.b].insert(z);
		SS[z.b.a].insert(z);
	}
	
	set<P>th;
	set<P1>allth;
	vc<int>zanz(n+1, 1e18);
	rep(i, m){
		auto z = query[i].b;
		int u = z.b.a, v = z.b.b;
		if(SS[u].order_of_key(z) <= 2 and SS[v].order_of_key(z) <= 2){
			allth.insert(z);
		}
	}
	
	auto recalc = [&](int i){
		if(th.find(mp(zanz[i], i)) != th.end()) th.erase(mp(zanz[i], i));
		{
			int tmp = 4;
			auto it = SS[i].begin();
			zanz[i] = 0;
			while(tmp and it != SS[i].end()){
				auto at = *it;
				if(tmp > 1 and allth.find(at) == allth.end()){
					if(SS[at.b.a].order_of_key(at) <= 2 and 
					SS[at.b.b].order_of_key(at) <= 2){
						allth.insert(at);
					}
				}
				else if(tmp <= 1 and allth.find(at) != allth.end()){
					allth.erase(at);
				}
				if(tmp > 1) zanz[i] += at.a;
				tmp --;
				it ++;
			}
			if(SS[i].size() < 3) zanz[i] = 1e18;
		}
		th.insert(mp(zanz[i], i));
	};
	repn(i, n) recalc(i);
	
	auto get_max = [&](){
		auto it = allth.begin();
		auto curmin = *it;
		int u = curmin.b.a, v = curmin.b.b, w = curmin.a;
		vc<P1>cand({curmin});
		it ++;
		int ret = 1e18;
		while(it != allth.end()){
			auto zan = *it;
			int uu = zan.b.a, vv = zan.b.b, ww = zan.a;
			if(u != uu and v != uu and u != vv and v != vv){
				chmin(ret, w+ww);
				break;
			}
			else{
				cand.pb(zan);
				it++;
			}
		}
		assert(cand.size() <= 6);
		rep(i, cand.size()) rep(j, i){
			if(cand[i].b.a != cand[j].b.a and cand[i].b.a != cand[j].b.b){
				if(cand[i].b.b != cand[j].b.a and cand[i].b.b != cand[j].b.b){
					chmin(ret, cand[i].a + cand[j].a); break;
				}
			}
		}
		return min(ret, (*th.begin()).a);
	};
	o(get_max());
	for(int j=m;j<m+q;j++){
		int t = query[j].a;
		if(t == 1){
			auto z = query[j].b;
			SS[z.b.b].insert(z);
			SS[z.b.a].insert(z);
			recalc(z.b.a);
			recalc(z.b.b);
		}
		else{
			auto z = query[j].b;
			SS[z.b.b].erase(z);
			SS[z.b.a].erase(z);
			if(allth.find(z) != allth.end()) allth.erase(z);
			recalc(z.b.a);
			recalc(z.b.b);
		}
		o(get_max());
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t=1;//cin >> t;
	while(t--) solve();
}