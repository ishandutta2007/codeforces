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

//long number
//not carefully tested yet...
 
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
//need: min(a.size(), b.size()) < 1e6 + eps
template<class T>
vector<T> anyntt(vector<T>&a, vector<T>&b, int eq = 0) {
	const int m1 = 998244353, m2 = 1004535809;
	ntt<m1>n1;
	ntt<m2>n2;
	auto a1 = n1.multiply(a, b, eq);
	auto a2 = n2.multiply(a, b, eq);
	const int n = a1.size();
	vector<int>ret(n);
	rep(i, n){
        //a1[i] + m1*x = a2[i] + m2*y
		ret[i] = ((a2[i]-a1[i])*669690699LL%m2+m2)%m2 * m1 + a1[i];
	}
	return ret;
}
 
//base 1000000
const int base = 1000000;
//all values are non-negative
void norm(vc<int> &l){
	rep(i, l.size()){
		if(l[i] >= base){
			if(i+1 == l.size()) l.pb(0);
			l[i+1] += l[i] / base;
			l[i] %= base;
		}
	}
}
struct lng{
	vector<int>num;
	bool minus;
	lng(){num=vc<int>({0});minus=false;}
	lng(vector<int>vec, bool tp){
		if(vec.empty()) vec.pb(0);
		num = vec;
		minus = tp;
	}
	lng(int v){
		if(v < 0){
			minus = true;
			v = -v;
		}
		else minus = false;
		vc<int>nxt;
		while(v){
			nxt.pb(v%base);
			v /= base;
		}
		if(nxt.empty()) nxt.pb(0);
		num = nxt;
	}
	lng(string s){
		if(s.empty()) s = "0";
		bool par = (s[0] == '-');
		string t = s;
		if(par){
			reverse(all(s)); s.pop_back(); reverse(all(s));
		}
		vc<int>tmp;
		int sz = s.size();
		for(int i=sz-1;i>=0;i-=6){
			int v = 0;
			rep(j, 6){
				if(i+j-5 < 0) continue;
				v = v*10 + (s[i+j-5]-'0');
			}
			tmp.pb(v);
		}
		if(par) s = t;
		num = tmp;
		minus = par;
	}
	lng operator-() const{
		lng ret;
		ret.num = num;
		ret.minus = minus ^ 1;
		return ret;
	}
	lng operator+(const lng &r) const {
		vc<int>ret(max(num.size(), r.num.size()), 0);
		rep(i, num.size()) ret[i] += (minus?-num[i]:num[i]);
		rep(i, r.num.size()) ret[i] += (r.minus?-(r.num)[i]:(r.num)[i]);
		bool neg = false;
		rep(i, ret.size()){
			if(ret[i] < 0){
				if(i+1 == ret.size()) {
					neg = true;
					break;
				}
				auto need = -ret[i];
				need = (need+base-1) / base;
				ret[i] += need * base;
				ret[i+1] -= need;
			}
			else if(ret[i] >= base){
				if(i+1 == ret.size()) ret.pb(0);
				ret[i+1] += ret[i] / base;
				ret[i] %= base;
			}
		}
		if(neg){
			bool ex = 0;
			rep(i, ret.size()) {
				ret[i] = -ret[i];
				if(i+1 < ret.size() and ret[i]) ex = 1;
			}
			if(ex){
				rep(i, ret.size()-1) ret[i] += (i==0?base:base-1);
				ret.back() --;
			}
			norm(ret);
		}
		while(ret.size() > 1 and ret.back() == 0) ret.pop_back();
		return {ret, neg};
	}
	lng operator-(const lng &r) const { return *this + (-r); }
	lng operator*(const lng &r) const {
		if(num.empty() or num == vc<int>({0}) or r.num.empty() or r.num == vc<int>({0})){
			return {vc<int>({0}), false};
		}
		vc<int>rn = num, rp = r.num;
		vc<int>ret = anyntt(rn, rp);
		bool neg = minus ^ r.minus;
		norm(ret);
		return {ret, neg};
	}
	lng operator+(int v) const {
		vc<int>add;
		bool addm = false;
		if(v < 0){
			addm ^= 1;
			v = -v;
		}
		while(v){
			add.pb(v % base);
			v /= base;
		}
		return *this + (lng){add, addm};
	}
	lng operator-(int v) const { return *this + (-v); }
	lng operator*(int v) const {
		if(v == 0){
			return {vc<int>({0}), false};
		}
		bool neg = minus;
		vc<int>ret = num;
		if(v < 0) {
			neg ^= 1;
			v = -v;
		}
		rep(i, ret.size()) ret[i] *= v;
		norm(ret);
		return {ret, neg};
	}
	pair<lng, int> operator/(int v) const {
		assert(v);
		bool neg = minus;
		vc<int>ret = num;
		if(v < 0) {
			neg ^= 1;
			v = -v;
		}
		int up = 0;
		assert(ret.size());
		for(int i=ret.size()-1;i>=0;i--){
			up = up * base + ret[i];
			ret[i] = up / v;
			up %= v;
		}
		while(ret.size() > 1 and ret.back() == 0) ret.pop_back();
		return mp((lng){ret, neg}, up);
	}
	int operator%(int v) const {
		assert(v);
		bool neg = minus;
		vc<int>ret = num;
		if(v < 0) {
			neg ^= 1;
			v = -v;
		}
		int up = 0;
		assert(ret.size());
		for(int i=ret.size()-1;i>=0;i--){
			up = up * base + ret[i];
			ret[i] = up / v;
			up %= v;
		}
		while(ret.size() > 1 and ret.back() == 0) ret.pop_back();
		return up;
	}
	lng& operator+=(const lng &r) { return *this = *this + r; }
	lng& operator-=(const lng &r) { return *this = *this - r; }
	lng& operator*=(const lng &r) { return *this = *this * r; }
	lng& operator+=(const int &v) { return *this = *this + v; }
	lng& operator-=(const int &v) { return *this = *this - v; }
	lng& operator*=(const int &v) { return *this = *this * v; }
	lng& operator/=(const int &v) { return *this = (*this / v).a; }
	
	bool operator<(const lng &r) const { 
		if(minus != r.minus){
			return (int)minus > (int)r.minus;
		}
		if(num.size() != r.num.size()){
			return minus ^ (num.size() < r.num.size());
		}
		int sz = num.size();
		for(int i=sz-1;i>=0;i--){
			if(num[i] != r.num[i]){
				return minus ^ (num[i] < r.num[i]);
			}
		}
		return false;
	}
	bool operator>(const lng &r) const { return r < *this; }
	bool operator<=(const lng &r) const { return !(r < *this); }
	bool operator>=(const lng &r) const { return r <= *this; }
	bool operator==(const lng &r) const { return (*this <= r) && (r <= *this); }
	bool operator!=(const lng &r) const { return !(r == *this); }
	
	void write(){
		if(minus) cout << "-";
		int sz = num.size();
		string ret = "";
		for(int i=sz-1;i>=0;i--){
			int val[6] = {100000, 10000, 1000, 100, 10, 1}, v = num[i];
			rep(j, 6){
				int num = v / val[j]; v %= val[j];
				if(ret.empty() and !num) continue;
				ret.pb('0'+num);
			}
		}
		if(ret.empty()) ret = "0";
		cout<<ret<<endl;
	}
	vc<int> get_digit(){
		int sz = num.size();
		vc<int>ret;
		for(int i=sz-1;i>=0;i--){
			int val[6] = {100000, 10000, 1000, 100, 10, 1}, v = num[i];
			rep(j, 6){
				int num = v / val[j]; v %= val[j];
				if(ret.empty() and !num) continue;
				ret.pb(num);
			}
		}
		if(ret.empty()) ret.pb(0);
		return ret;
	}
	string get_str(){
		string ret = "";
		if(minus) ret = "-";
		int sz = num.size();
		for(int i=sz-1;i>=0;i--){
			int val[6] = {100000, 10000, 1000, 100, 10, 1}, v = num[i];
			rep(j, 6){
				int num = v / val[j]; v %= val[j];
				if(ret.empty() and !num) continue;
				ret.pb('0'+num);
			}
		}
		if(ret.empty()) ret = "0";
		return ret;
	}
};
const lng operator+(int v, const lng &r){
	return r+v;
}
const lng operator-(int v, const lng &r){
	return -r+v;
}
const lng operator*(int v, const lng &r){
	return r*v;
}

void solve(){
	string s; cin >> s;
	if(s == "1"){
		o(1);
		return;
	}
	lng val = s;
	int len = s.size() - 1;
	double d = log10(3);
	d = (double)(len) / d;
	int from = max(0LL, (int)(floor(d))-2);
	vc<lng>bin;
	bin.pb(lng(3));
	for(int i=0;(2<<i)<=from;i++){
		bin.pb(bin.back()*bin.back());
	}
	lng beg = 1;
	int ptr = 0;
	int from2 = from;
	while(from){
		if(from & 1) beg = beg * bin[ptr];
		ptr ++;
		from /= 2;
	}
	from = from2;
	int best = INF;
	
	for(int b=0;b<=2;b++){
		auto cur = beg;
		int zan = from;
		while(cur < val) {
			cur *= 3;
			zan ++;
		}
		chmin(best, b*2 + zan*3);
		auto nxt = val / 2;
		if(nxt.b == 1){
			nxt.a += 1;
		}
		val = nxt.a;
	}
	o(best);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}