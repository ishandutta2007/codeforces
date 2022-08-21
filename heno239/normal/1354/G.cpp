#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

void chmin(ll &a, ll b) {
	a = min(a, b);
}
void chmax(ll &a, ll b) {
	a = max(a, b);
}
ll mod_pow(ll a, ll n, ll m = mod) {
	a %= m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
const int max_n = 1 << 18;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

string query(vector<int> &a, vector<int> &b) {
	cout << "? "<<a.size() << " " << b.size() << endl;
	rep(i, a.size()) {
		if (i > 0)cout << " ";
		cout << a[i]+1;
	}
	cout << endl;
	rep(i, b.size()) {
		if (i > 0)cout << " ";
		cout << b[i]+1;
	}
	cout << endl;
	string res; cin >> res; return res;
}
void solve() {
	int n, k; cin >> n >> k;
	int le = 0, ri = n;
	while (ri - le > 1) {
		int m = (le + ri) / 2;
		int len = ri - le;
		vector<int> a, b;
		rep(i, len / 2)a.push_back(le + i);
		rep(i, len / 2)b.push_back(le + (len + 1) / 2 + i);
		string q = query(a, b);
		if (q == "SECOND") {
			le += len / 2;
		}
		else{
			ri = le + (len + 1) / 2;
		}
	}
	vector<bool> non(n, false);
	non[le] = true;

	vector<int> ct;
	rep(i, 11) {
		int num = (1 << i);
		if (num * 2 > n) {
			rep(j, n)if (!non[j]) {
				ct.push_back(j);
			}
			break;
		}
		vector<int> a;
		rep(j, n) {
			if (non[j])continue;
			if (a.size() < num)a.push_back(j);
		}
		vector<int> b;
		rep(j, n) {
			if (non[j] && b.size() < num)b.push_back(j);
		}
		string q = query(a, b);
		if (q == "EQUAL") {
			for (int id : a) {
				non[id] = true;
			}
		}
		else {
			ct = a; break;
		}
	}
	while (ct.size() > 1) {
		vector<int> a;
		int len = ct.size() / 2;
		rep(i, len)a.push_back(ct[i]);
		vector<int> b;
		rep(i, n) {
			if (non[i] && b.size() < len)b.push_back(i);
		}
		string q = query(a, b);
		if (q == "EQUAL") {
			ct.erase(ct.begin(), ct.begin() + len);
		}
		else {
			ct.resize(len);
		}
	}
	cout << "! "<<ct[0]+1 << endl;
}


signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	int t; cin >> t;
	rep(i, t)solve();
	//solve();
	stop
		return 0;
}