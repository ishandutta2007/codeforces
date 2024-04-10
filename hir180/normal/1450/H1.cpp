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
#define _sz 200005
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
template<const int md>
struct ntt{
	inline void add(int &a, int b) { a += b; if(a >= md) a -= md; }
	inline void sub(int &a, int b) { a -= b; if(a < 0) a += md; }
	inline int add2(int a, int b) { a += b; if(a >= md) a -= md; return a;}
	inline int sub2(int a, int b) { a -= b; if(a < 0) a += md; return a;}
	inline int mul(int a, int b) { return (int)((ll)a*b%md); }
	inline int power(int a, long long b) {
		int res = 1;
		while (b > 0) {
			if (b & 1) res = mul(res, a);
	    	a = mul(a, a);
			b >>= 1;
		}
		return res;
	}
	inline int inv(int a) {
		a %= md;
		if (a < 0) a += md;
		int b = md, u = 0, v = 1;
		while (a) {
			int t = b / a;
			b -= t * a; swap(a, b);
			u -= t * v; swap(u, v);
		}
		assert(b == 1);
		if (u < 0) u += md;
		return u;
	}
	
 	int max_base, root;
	vector<int> dw, idw;
	ntt() {
		int tmp = md - 1;
		max_base = 0;
		while (tmp % 2 == 0) {
			tmp /= 2;
			max_base++;
		}
		root = 2;
		while (power(root, (md-1)>>1) == 1) root++;
		dw.resize(max_base); idw.resize(max_base);
		rep(i, max_base){
			sub(dw[i], power(root, (md-1) >> (i+2)));
			idw[i] = inv(dw[i]);
		}
	}
	void fft(vector<int> &a, bool inv) {
		const int n = a.size();
		assert((n & (n - 1)) == 0);
		assert(__builtin_ctz(n) <= max_base);
		if(!inv){
			for(int m=n;m>>=1;){
				int w = 1;
				for(int s=0,k=0; s<n; s += 2*m){
					for(int i=s, j=s+m ; i < s+m; ++i, ++j) {
						int x = a[i], y = mul(a[j], w);
						a[j] = (x>=y?x-y:x+md-y);
						a[i] = (x+y>=md?x+y-md:x+y);
					}
					w = mul(w, dw[__builtin_ctz(++k)]);
				}
			}
		}
		else{
			for(int m=1;m<n;m*=2){
				int w = 1;
				for(int s=0,k=0; s<n; s += 2*m){
					for(int i=s, j=s+m ; i < s+m; ++i, ++j) {
						int x = a[i], y = a[j];
						a[j] = (x>=y?x-y:x+md-y);
						a[j] = mul(a[j], w);
						a[i] = (x+y>=md?x+y-md:x+y);
					}
					w = mul(w, idw[__builtin_ctz(++k)]);
				}
			}
		}
	}
	vector<int> multiply(vector<int> a, vector<int> b, int eq = 0) {
		int need = a.size() + b.size() - 1;
		int nbase = 0;
		while ((1 << nbase) < need) nbase++;
		int sz = 1 << nbase;
		a.resize(sz);
		b.resize(sz);
		fft(a, 0);
		if (eq) b = a; else fft(b, 0);
		int inv_sz = inv(sz);
		for (int i = 0; i < sz; i++) {
			a[i] = mul(mul(a[i], b[i]), inv_sz);
		}
		fft(a, 1);
		a.resize(need);
		return a;
	}
	vector<int> square(vector<int> a) {
		return multiply(a, a, 1);
	}
};
int n, m;
string s;

void solve(){
	make();
	cin>>n>>m>>s;
	ntt<998244353>fuyuko;
	int x = 0, y = 0, z = 0;
	rep(i, n){
		if(s[i] == 'b'){
			if(i%2 == 0) x ++;
			else x --;
		}
		else if(s[i] == '?'){
			if(i%2 == 0) y ++;
			else z ++;
		}
	}
	vc<int>yy, zz;
	rep(i, y+1) yy.pb(C(y, i));
	rep(i, z+1) zz.pb(C(z, i)); reverse(all(zz));
	auto yz = fuyuko.multiply(yy, zz);
	int way = 0, sum = 0;
	rep(i, yz.size()){
		int eval = x + i - z;
		if(eval%2 != 0) continue;
		way += yz[i];
		sum += yz[i]*abs(eval)/2%mod;
	}
	way = way%mod;
	sum = sum%mod;
	sum = sum*modpow(way,mod-2)%mod;
	o((sum%mod+mod)%mod);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t=1;//cin >> t;
	while(t--) solve();
}