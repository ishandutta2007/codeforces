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
const ll mod = 1000000007;
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

ll mod_pow(ll a, ll n, ll m = mod) {
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
const int max_n = 10000;
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

bool isint(string s) {
	if (s[0] == '0')return false;
	rep(i, s.size()) {
		if (s[i] < '0' || '9' < s[i]) {
			return false;
		}
	}
	return true;
}
void solve() {
	int n; cin >> n;
	vector<string> s(n);
	vector<bool> b(n);

	vector<int> toup, todow;
	rep(i, n) {
		cin >> s[i];
		int t; cin >> t; b[i] = t;
	}
	int e = 0;
	rep(i, n)if (b[i])e++;
	vector<bool> used(n + 1);
	vector<pair<string,bool>> gomi;
	rep(i, n) {
		if (!isint(s[i]))gomi.push_back({ s[i],b[i] });
		else {
			int z = stoi(s[i]);
			if (z <= 0 || z > n)gomi.push_back({ s[i],b[i] });
		}
		if (b[i]) {
			if (isint(s[i])) {
				int x = stoi(s[i]);
				if (x > e&&x<=n) {
					todow.push_back(i);
					used[x] = true;
				}
				else if (0<x&&x <= e) {
					used[x] = true;
				}
			}
		}
		else {
			if (isint(s[i])) {
				int x = stoi(s[i]);
				if (0<x&&x <= e) {
					toup.push_back(i);
					used[x] = true;
				}
				else if (e < x&&x <= n) {
					used[x] = true;
				}
			}
		}
	}
	//cout << toup.size() << " " << todow.size() << " " << gomi.size() << "\n";
	bool exi = false;
	rep1(i, n)if (!used[i])exi = true;
	if (!exi) {
		if (toup.size() == 0) {
			cout << 0 << "\n"; return;
		}
		assert(toup.size() == todow.size());
		int len = toup.size();
		string cur = "heno";
		vector<pair<string, string>> ans;
		rep(i, len) {
			ans.push_back({ s[toup[i]],cur });
			cur = s[toup[i]];
			ans.push_back({ s[todow[i]],cur });
			cur = s[todow[i]];
		}
		ans.push_back({ "heno",cur });
		cout << ans.size() << "\n";
		rep(i, ans.size()) {
			cout << "move " << ans[i].first << " " << ans[i].second << "\n";
		}
		return;
	}
	set<int> restdow, restup;
	rep1(i, n) {
		if (!used[i]) {
			if (i <= e)restdow.insert(i);
			else restup.insert(i);
		}
	}
	vector<pair<string, string>> ans;
	while (toup.size() > 0 || todow.size() > 0) {
		if (toup.size() > 0&&restup.size()>0) {
			int from = stoi(s[toup.back()]);
			int to = *restup.begin();
			ans.push_back({ to_string(from),to_string(to) });
			restup.erase(restup.begin());
			restdow.insert(from);
			toup.pop_back();
		}
		if (todow.size() > 0 && restdow.size() > 0) {
			int from = stoi(s[todow.back()]);
			int to = *restdow.begin();
			ans.push_back({ to_string(from),to_string(to) });
			restdow.erase(restdow.begin());
			restup.insert(from);
			todow.pop_back();
		}
	}
	rep(i, gomi.size()) {
		if (gomi[i].second) {
			int to = *restdow.begin();
			ans.push_back({ gomi[i].first,to_string(to) });
			restdow.erase(restdow.begin());
		}
		else {
			int to = *restup.begin();
			ans.push_back({ gomi[i].first,to_string(to) });
			restup.erase(restup.begin());
		}
	}
	cout << ans.size() << "\n";
	rep(i, ans.size()) {
		cout << "move " << ans[i].first << " " << ans[i].second << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//experi();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}