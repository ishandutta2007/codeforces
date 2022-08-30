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
//#define rng(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#define pcnt(x) __builtin_popcountll(x)

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
	//don't make x negative!
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

struct modular{
	ll v;
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(ll vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular &operator+=(const modular&rhs){return s(v+rhs.v);}
	modular &operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular &operator*=(const modular&rhs){v=ll(v)*rhs.v%mod;return *this;}
	modular &operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(ll n)const{
		if(n<0)return inv().pow(-n);
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	friend modular operator+(ll x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(ll x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(ll x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(ll x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};
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
modular F[_sz],R[_sz];
void make(){
	F[0] = 1;
	for(int i=1;i<_sz;i++) F[i] = F[i-1] * i;
	R[_sz-1] = F[_sz-1].pow(mod-2);
	for(int i=_sz-2;i>=0;i--) R[i] = R[i+1] * (i+1);
}
modular C(int a,int b){
	if(b < 0 || a < b) return modular();
	return F[a]*R[b]*R[a-b];
}
//o(ans?"Yes":"No");

//verified yosupo judge
ll gcd(ll a,ll b){
	if(a < b) swap(a,b);
	if(b == 0) return a;
	else return gcd(b,a%b);
}
namespace miller_rabin{
    ll mul(ll x, ll y, ll mod){
    	return (__int128) x * y % mod;
    }
	ll ipow(ll x, ll y, ll p){
		ll ret = 1, piv = x % p;
		while(y){
			if(y&1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(ll x, ll a){
		if(x % a == 0) return 0;
		ll d = x - 1;
		while(1){
			ll tmp = ipow(a, d, x);
			if(d&1) return (tmp != 1 && tmp != x-1);
			else if(tmp == x-1) return 0;
			d >>= 1;
		}
	}
	bool isprime(ll x){
		for(auto &i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
			if(x == i) return 1;
			if(x > 40 && miller_rabin(x, i)) return 0;
		}
		if(x <= 40) return 0;
		return 1;
	}
};
namespace pollard_rho{
	ll f(ll x, ll n, ll c){
		return (c + miller_rabin::mul(x, x, n)) % n;
	}
	void rec(ll n, vector<ll> &v){
		if(n == 1) return;
		if(n % 2 == 0){
			v.push_back(2);
			rec(n/2, v);
			return;
		}
		if(miller_rabin::isprime(n)){
			v.push_back(n);
			return;
		}
		mt19937_64 mt(61471 + v.size());
		ll a, b, c;
		while(1){
			a = mt() % (n-2) + 2;
			b = a;
			c = mt() % 20 + 1;
			do{
				a = f(a, n, c);
				b = f(f(b, n, c), n, c);
			}while(gcd(abs(a-b), n) == 1);
			if(a != b) break;
		}
		ll x = gcd(abs(a-b), n);
		rec(x, v);
		rec(n/x, v);
	}
	vector<ll> factorize(ll n){
		vector<ll> ret;
		rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
};
namespace pollard_rho_fast{
	ll f(ll x, ll n, ll c){
		return (c + miller_rabin::mul(x, x, n)) % n;
	}
	void rec(ll n, vector<ll> &v){
		if(n == 1) return;
		if(n % 2 == 0){
			v.push_back(2);
			rec(n/2, v);
			return;
		}
		if(miller_rabin::isprime(n)){
			v.push_back(n);
			return;
		}
		mt19937_64 mt(61471 + v.size());
		while(true){
    		ll c = mt() % (n-3) + 1;
    		ll y = mt() % (n-2) + 1;
    		ll x = 0, g = 1, r = 1, m = 500, ys = 0, q = 1;
    		
    		while(g == 1){
    			x = y;
    			rep(i, r) y = f(y, n, c);
    			ll k = 0;
    			g = 1;
    			while(k < r and g == 1){
    				ys = y;
    				for(int i=1;i<=min(m, r-k);i++){
    					y = f(y, n, c);
    					q = miller_rabin::mul(q, abs(x-y), n);
    				}
    				g = gcd(q, n);
    				k += m;
    			}
    			r <<= 1;
    		}
    		if(g == n) g = 1;
    		while(g == 1){
    			ys = f(ys, n, c);
    			g = gcd(abs(x-ys), n);
    		}
    		if(g != n) {
    		    rec(g, v);
		        rec(n/g, v);
		        return;
    		}
		}
	}
	vector<ll> factorize(ll n){
		vector<ll> ret;
		rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
	vector<pair<ll, int>> factorize2(ll n){
		vc<pair<ll, int>>vec;
		auto v = factorize(n);
		for(int j=0;j<v.size();j++){
			int k = j;
			while(k < v.size() and v[j] == v[k]) k ++;
			vec.eb(v[j], k-j);
			j = k-1;
		}
		return vec;
	}
	//not sorted
	vector<ll> divisor(vector<pair<ll, int>>vec){
		if(vec.empty()) return vc<ll>{1LL};
		auto p = vec.back();
		vec.pop_back();
		vector<ll>ret = divisor(vec);
		vector<ll>nret;
		nret.reserve(ret.size() * (p.b+1));
		rep(i, ret.size()){
			ll r = ret[i];
			rep(j, p.b+1){
				nret.pb(r);
				if(j == p.b) break;
				r *= p.a;
			}
		}
		return nret;
	}
	//not sorted
	vector<ll> divisor(ll n){
		return divisor(factorize2(n));
	}
};
void solve(){
	int n, q; cin >> n >> q;
	auto pp = pollard_rho_fast::factorize2(n);
	vc<vc<int>>zan(pp.size(), vc<int>(n, 0));
	vc<int>sz(pp.size());
	rep(i, pp.size()) sz[i] = n / (pp[i].a);
	
	vc<int>a(n);
	rep(i, n){
		cin >> a[i];
		rep(j, pp.size()){
			zan[j][i%sz[j]] += a[i];
		}
	}
	set<pair<int, P>>S;
	rep(i, pp.size()){
		rep(j, sz[i]){
			S.insert(mp(zan[i][j] * (n/pp[i].a), mp(i, j)));
		}
	}
	auto ans = [&](){
		auto it = S.end(); 
		it --;
		o((*it).a);
		return;
	};
	ans();
	rep(i, q){
		int p, x; cin >> p >> x;
		p--;
		rep(j, pp.size()){
			S.erase(mp(zan[j][p%sz[j]] * (n/pp[j].a), mp(j, p%sz[j])));
			zan[j][p%sz[j]] += x - a[p];
			S.insert(mp(zan[j][p%sz[j]] * (n/pp[j].a), mp(j, p%sz[j])));
		}
		a[p] = x;
		ans();
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}