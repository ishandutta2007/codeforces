

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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
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
const int max_n = 1 << 21;
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


vector<string> expr(string& s, int& i);
vector<string> term(string& s, int& i);
vector<string> atom(string& s, int& i);
vector<string> letter(string& s, int& i);

vector<string> expr(string& s, int& i) {
	//cout << "? " << i << "\n";
	vector<vector<string>> terms;
	terms.push_back(term(s, i));
	while (i < s.size() && s[i] == '|') {
		i++;
		terms.push_back(term(s, i));
	}
	if (terms.size() == 1) {
		return terms[0];
	}
	int n = 0;
	rep(i, terms.size()) {
		if (i > 0)n++;
		n += terms[i].size();
	}
	int m = 0;
	rep(i, terms.size()) {
		m = max(m, (int)terms[i][0].size());
	}
	m += 6;
	int ad = 0;
	vector<string> res(n);
	rep(i, n)res[i].resize(m, ' ');
	rep(i, terms.size()) {
		if (i > 0)ad++;
		res[ad + 1][0] = '+';
		res[ad + 1][1] = '-';
		res[ad + 1][2] = '>';
		res[ad + 1][m-3] = '-';
		res[ad + 1][m-2] = '>';
		res[ad + 1][m-1] = '+';
		rep(j, terms[i].size())rep(k, terms[i][j].size()) {
			res[ad + j][k + 3] = terms[i][j][k];
		}
		for (int j = terms[i][0].size() + 3; j < m - 3; j++) {
			res[ad + 1][j] = '-';
		}
		ad += terms[i].size();
	}
	for (int i = 2; i <= n - terms.back().size(); i++) {
		if (res[i][0] != '+') {
			res[i][0] = '|';
			res[i][m - 1] = '|';
		}
	}
	return res;
}
vector<string> term(string& s, int& i) {
	vector<string> res = atom(s, i);
	while (i < s.size() && s[i] != '|'&&s[i]!=')') {
		vector<string> nex = atom(s, i);
		int n = max(res.size(), nex.size());
		int m = res[0].size() + nex[0].size() + 2;
		vector<string> nres(n);
		rep(i, n) {
			nres[i].resize(m, ' ');
		}
		rep(i, res.size())rep(j, res[i].size()) {
			nres[i][j] = res[i][j];
		}
		//cout << res[0].size() << " " << nex[0].size() << "\n";
		nres[1][res[0].size()] = '-';
		nres[1][res[0].size() + 1] = '>';
		rep(i, nex.size())rep(j, nex[i].size()) {
			nres[i][j + res[0].size() + 2] = nex[i][j];
		}
		swap(res, nres);
	}
	return res;
}
vector<string> atom(string& s, int& i) {
	vector<string> res;
	if (s[i] == '(') {
		i++;
		res = expr(s, i);
		i++;
	}
	else {
		assert(s[i] >= 'A' && s[i] <= 'Z');
		res = letter(s, i);
	}
	while (i < s.size() && (s[i] == '+' || s[i] == '*' || s[i] == '?')) {
		char c = s[i]; i++;
		if (c == '+') {
			int n = res.size()+2;
			int m = res[0].size()+6;
			vector<string> nres(n);
			rep(i, n)nres[i].resize(m,' ');
			rep(i, res.size())rep(j, res[i].size()) {
				nres[i][j + 3] = res[i][j];
			}
			nres[1][0] = '+';
			nres[1][1] = '-';
			nres[1][2] = '>';
			nres[1][m - 3] = '-';
			nres[1][m - 2] = '>';
			nres[1][m - 1] = '+';
			for (int i = 2; i < n; i++) {
				nres[i][0] = nres[i][m - 1] = '|';
			}
			nres[n - 1][0] = '+';
			nres[n - 1][1] = '<';
			nres[n - 1][m - 1] = '+';
			for (int j = 2; j < m - 1; j++) {
				nres[n - 1][j] = '-';
			}
			swap(res, nres);
		}
		else if (c == '?') {
			int n = res.size() + 3;
			int m = res[0].size() + 6;
			vector<string> nres(n);
			rep(i, n)nres[i].resize(m, ' ');
			rep(i, res.size())rep(j, res[i].size()) {
				nres[i+3][j + 3] = res[i][j];
			}
			nres[4][0] = '+';
			nres[4][1] = '-';
			nres[4][2] = '>';
			nres[4][m - 3] = '-';
			nres[4][m - 2] = '>';
			nres[4][m - 1] = '+';
			for (int i = 1; i < 4; i++) {
				nres[i][0] = nres[i][m - 1] = '|';
			}
			nres[1][0] = '+';
			nres[1][m - 2] = '>';
			nres[1][m - 1] = '+';
			for (int j = 1; j < m - 2; j++) {
				nres[1][j] = '-';
			}
			swap(res, nres);
		}
		else {
			int n = res.size() + 5;
			int m = res[0].size() + 6;
			vector<string> nres(n);
			rep(i, n)nres[i].resize(m, ' ');
			rep(i, res.size())rep(j, res[i].size()) {
				nres[i + 3][j + 3] = res[i][j];
			}
			nres[4][0] = '+';
			nres[4][1] = '-';
			nres[4][2] = '>';
			nres[4][m - 3] = '-';
			nres[4][m - 2] = '>';
			nres[4][m - 1] = '+';
			for (int i = 1; i < 4; i++) {
				nres[i][0] = nres[i][m - 1] = '|';
			}
			nres[1][0] = '+';
			nres[1][m - 2] = '>';
			nres[1][m - 1] = '+';
			for (int j = 1; j < m - 2; j++) {
				nres[1][j] = '-';
			}
			for (int i = 5; i < n - 1; i++) {
				nres[i][0] = nres[i][m - 1] = '|';
			}
			nres[n - 1][0] = '+';
			nres[n - 1][1] = '<';
			nres[n - 1][m - 1] = '+';
			for (int j = 2; j < m - 1; j++) {
				nres[n - 1][j] = '-';
			}
			swap(res, nres);
		}
	}
	return res;
}
vector<string> letter(string& s, int& i) {
	string cur;
	while (i < s.size() && s[i] >= 'A' && s[i] <= 'Z') {
		cur.push_back(s[i]); i++;
	}
	if (i < s.size() && (s[i] == '*' || s[i] == '+' || s[i] == '?') && cur.size()>1) {
		cur.pop_back(); i--;
	}
	vector<string> res(3);
	rep(i, 3) {
		res[i].resize(cur.size() + 4, '-');
		res[i][0] = '+';
		res[i].back() = '+';
	}
	rep(j, cur.size())res[1][j + 2] = cur[j];
	res[1][1] = res[1][2 + cur.size()] = ' ';
	return res;
}


void solve() {
	string s; cin >> s;
	int i = 0;
	vector<string> ans = expr(s, i);
	int n = ans.size();
	int m = ans[0].size() + 6;
	vector<string> nans(n);
	rep(i, n) {
		nans[i].resize(m,' ');
	}
	rep(i, ans.size()) {
		rep(j, ans[i].size()) {
			nans[i][j + 3] = ans[i][j];
		}
	}
	nans[1][0] = 'S';
	nans[1][1] = '-';
	nans[1][2] = '>';
	nans[1][m - 3] = '-';
	nans[1][m - 2] = '>';
	nans[1][m - 1] = 'F';
	swap(ans, nans);
	cout << ans.size() << " " << ans[0].size() << "\n";
	rep(i, ans.size())cout << ans[i] << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();

	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}