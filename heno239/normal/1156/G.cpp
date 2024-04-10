#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	//if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 20;
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
template<typename T>
void addv(vector<T>& v,int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}
//-----------------------------------------

string ord = "$^#&";
int trans(char c) {
	if (c == '$')return 0;
	else if (c == '^')return 1;
	else if (c == '#')return 2;
	else if (c == '&')return 3;
	else return -1;
}

void solve() {
	int n; cin >> n;
	vector<string> s(n);
	rep(i, n)cin >> s[i];
	map<string, int> mp;
	using ar = array<int, 3>;
	vector<ar> ch;
	map<ar, int> mpp;
	vector<string> ori;
	int las = -1;
	rep(i, n) {
		vector<string> ns;
		int typ = -1;
		int le = 0;
		rep(j, s[i].size()) {
			if (s[i][j] == '=') {
				string u = s[i].substr(le, j - le);
				ns.push_back(u);
				le = j + 1;
			}
			if (trans(s[i][j]) >= 0) {
				string u = s[i].substr(le, j - le);
				ns.push_back(u);
				le = j + 1;
				typ = trans(s[i][j]);
			}
		}
		string u = s[i].substr(le, s[i].size() - le);
		ns.push_back(u);
		for (int i = 1; i < ns.size(); i++) {
			if (mp.find(ns[i]) == mp.end()) {
				int sz = ch.size();
				mp[ns[i]] = sz;
				ch.push_back({-1,-1,-1});
				ori.push_back(ns[i]);
			}
		}
		if (ns.size() == 2) {
			mp[ns[0]] = mp[ns[1]];
			if (ns[0] == "res")las = mp[ns[0]];
		}
		else {
			ar a = { mp[ns[1]],mp[ns[2]],typ };
			//if (a[0] > a[1])swap(a[0], a[1]);
			if (mpp.find(a) != mpp.end()) {
				mp[ns[0]] = mpp[a];
				if (ns[0] == "res")las = mp[ns[0]];
			}
			else {
				int sz = ch.size();
				mp[ns[0]] = sz;
				mpp[a] = sz;
				ch.push_back(a);
				ori.push_back("?");
				if (ns[0] == "res")las = sz;
			}
		}
	}
	//for (string s : ori)cout << s << "\n";
	//cout << "? " << las << "\n";
	if(las<0){
		cout << 0 << "\n"; return;
	}
	if (ch[las][0] >= 0) {
		ori[las] = "res";
	}
	string cur = "aaaa";
	auto nex = [&](string s) {
		s[0]++;
		rep(i, 4) {
			if (s[i] == 'z') {
				s[i] = 'a';
				s[i + 1]++;
			}
			else break;
		}
		return s;
	};
	rep(i, ori.size()) {
		if (ori[i] == "?") {
			while (mp.find(cur) != mp.end()) {
				cur = nex(cur);
			}
			ori[i] = cur;
			cur = nex(cur);
		}
	}
	vector<string> anss;
	vector<bool> exi(ch.size());
	exi[las] = true;
	per(i, (int)ch.size()) {
		if (exi[i]) {
			if (ch[i][0] >= 0) {
				rep(j, 2)exi[ch[i][j]] = true;
			}
		}
	}
	//cout << "! " << las << " " << ori[las] << "\n";
	rep(i, ch.size())if(exi[i]) {
		if (ch[i][0] >= 0) {
			string c;
			c += ori[i];
			c += "=";
			c += ori[ch[i][0]];
			c += ord[ch[i][2]];
			c += ori[ch[i][1]];
			anss.push_back(c);
		}
	}
	if (ch[las][0] < 0) {
		if (ori[las] != "res") {
			string c;
			c += "res=";
			c += ori[las];
			anss.push_back(c);
		}
	}
	string c;
	/*c += "res=";
	c += ori[las];
	anss.push_back(c);*/
	cout << anss.size() << "\n";
	for (string s : anss)cout << s << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}