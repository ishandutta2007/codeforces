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

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

ll garner(vector<ll>b, vector<ll>m, ll mod){
    b.emplace_back(0);
    m.emplace_back(mod);

    vector<ll> coffs(b.size(), 1);
    vector<ll> constants(b.size(), 0);
    for(int i=0;i<b.size()-1;i++){
        ll v = (__int128)(b[i] - constants[i]) * mod_inv<ll>(coffs[i], m[i]) % m[i];
        if (v < 0) v += m[i];

        for (int j = i + 1; j < b.size(); j++) {
            (constants[j] += (__int128)coffs[j] * v) %= m[j];
            (coffs[j] *= (__int128)m[i]) %= m[j];
        }
    }

    return constants[b.size() - 1];
}
ll gcd(ll a, ll b){
    if(a<b)swap(a,b);
    if(b==0) return a;
    else return gcd(b,a%b);
}

//not solvable, return -1.
//otherwise, make m coprime and return lcm of m
ll preGarner(vector <ll> &b, vector <ll> &m, ll MOD) {
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < i; j++) {
            ll g = gcd(m[i], m[j]);
            if ((b[i] - b[j]) % g != 0) return -1;

            m[i] /= g, m[j] /= g;
            ll gi = gcd(m[i], g), gj = g / gi;
            do {
                g = gcd(gi, gj);
                gi *= g, gj /= g;
            } while (g != 1);
            m[i] *= gi, m[j] *= gj;
            b[i] %= m[i], b[j] %= m[j];
        }
    }

    ll res = 1;
    for (int i = 0; i < b.size(); i++) (res *= m[i]) %= MOD;
    return res;
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vc<int>a(k);
	int sum = 1;
	rep(i, k) {
		cin >> a[i];
		int v = a[i] / gcd(sum, a[i]);
		if(n/sum < v){
			o("NO"); return;
		}
		sum *= v;
	}
	if(n < sum) {
		o("NO"); return;
	}
	vc<P>pr;
	for(int v=2;v*v<=sum;v++){
		if(sum%v != 0) continue;
		int tmp = 0;
		while(sum % v == 0){
			tmp ++;
			sum /= v;
		}
		pr.pb(mp(v, tmp));
	}
	if(sum > 1) pr.pb(mp(sum, 1));
	
	vc<ll>_b, _m;
	for(auto aa:pr){
		int p = aa.a, cnt = aa.b;
		rep(i, k){
			int _s = a[i], gen = 0, vv = 1;
			while(_s % p == 0){
				_s /= p;
				vv *= p;
				gen ++;
			}
			if(gen == cnt){
				_b.pb((vv+(vv-i)%vv)%vv);
				_m.pb(vv);
				break;
			}
		}
	}
	auto f = preGarner(_b, _m, m+1);
	if(f == -1){
		o("NO"); return;
	}
	int x = garner(_b, _m, 1e18);
	if(x == 0) x += f;
	if(1 <= x and x+k-1 <= m){
		rep(add,k){
			if(a[add] != gcd(f, x+add)){
				goto nxt;
			}
		}
		o("YES"); return;
		nxt:;
	}
	o("NO");
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}