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
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
int mod, repcnt;
hash_table<ll,ll>M;
int t=0;
ll modpow(ll x,ll n){
    if(M.find(x) != M.end()) return M[x];
    ll kx = x;
    t++;
	int res=1;
	while(n>0){
		if(n&1) res=(__int128)res*x%mod;
		x=(__int128)x*x%mod;
		n>>=1;
	}
	return M[kx] = res;
}
#define pcnt(v) __builtin_popcount(v)
//ornot verified
template<class T, int mx=20>
vc<T>bitwise_conv(vc<T>p, vc<T>q, bool tmod = true){
	int n = p.size();
	int b = 0;
	while((1<<b) < n) b++;
	assert(b <= mx);
	
	auto fwt = [&](vc<T>&a){
		for(int d=1;d<n;d<<=1){
			for(int m=d<<1,i=0;i<n;i+=m){
				rep(j, d){
					auto x = a[i+j], y = a[i+j+d];
					//xor;
					a[i+j] = x+y, a[i+j+d] = (x-y+mod);
					//and
					//a[i+j] = x+y;
					//or
					//a[i+j+d] = x+y;
					if(tmod && a[i+j] >= mod) a[i+j] -= mod;
					if(tmod && a[i+j+d] >= mod) a[i+j+d] -= mod;
				}
			}
		}
	};
	auto ufwt = [&](vc<T>&a){
		for(int d=1;d<n;d<<=1){
			for(int m=d<<1,i=0;i<n;i+=m){
				rep(j, d){
					auto x = a[i+j], y = a[i+j+d];
					//xor;
					a[i+j] = (x+y), a[i+j+d] = (x-y+mod);
					//and
					//a[i+j] = x-y+mod;
					//or
					//a[i+j+d] = y-x+mod;
					if(tmod && a[i+j] >= mod) a[i+j] -= mod;
					if(tmod && a[i+j+d] >= mod) a[i+j+d] -= mod;
				}
			}
		}
	};
	fwt(p);
	fwt(q);
	rep(i, n) {
		p[i] = (__int128)p[i] * modpow(q[i], repcnt) %mod;
	}
	ufwt(p);
	return p;
}
void solve(){
	int m; cin >> m >> repcnt >> mod;
	mod <<= m;
	vc<int>a(1<<m);
	rep(i, (1<<m)) {
		cin >> a[i];
		a[i] %= mod;
	}
	vc<int>b(1<<m), gen(m+1);
	rep(i, m+1) cin >> gen[i];
	rep(i, (1<<m)) {
		b[i] = gen[pcnt(i)];
		b[i] %= mod;
	}
	auto ret = bitwise_conv(a, b);
	mod >>= m;
	rep(i, (1<<m)){
		assert(ret[i]%(1<<m) == 0);
		ret[i] /= (1<<m);
		ret[i] %= mod;
		if(ret[i] < 0) ret[i] += mod;
		
		o(ret[i]);
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}