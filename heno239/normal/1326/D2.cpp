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
const ll mod = 998244353;
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


int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void manacher(const string &s, vector<int> &r) {
	r.resize(s.size());
	int i = 0, j = 0;
	while (i < s.size()) {
		while (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j])++j;
		r[i] = j;
		int k = 1;
		while (i - k >= 0 && i + k < s.size() && k + r[i - k] < j)r[i + k] = r[i - k], ++k;
		i += k; j -= k;
	}
}

void solve() {
	string s; cin >> s;
	int n = s.size();
	int tmp = 0;
	rep(i, n) {
		if (s[i] == s[n - 1 - i])tmp++;
		else break;
	}
	if (tmp == n) {
		cout << s << "\n"; return;
	}
	string t = s;
	t.erase(t.begin(),t.begin() + tmp);
	t.erase(t.end() - tmp, t.end());
	string u;
	rep(i, t.size()) {
		if (i > 0)u.push_back('?');
		u.push_back(t[i]);
	}
	vector<int> r;
	int cl = -1, cr = -2;
	int ma = -1;
	manacher(u, r);
	int m = t.size();
	//cout << "! " << t << endl;
	rep(i, r.size()) {
		int len = r[i];
		int le, ri;
		if (i % 2 == 0) {
			le = i / 2 - (len-1) / 2;
			ri = i / 2 + (len-1) / 2;
		}
		else {
			le = i / 2 + 1 - len / 2;
			ri = i / 2 + len / 2;
		}
		//cout << i << " " << le << " " << ri << endl;
		if (le == 0 || ri == m - 1) {
			if (ri - le + 1 > ma) {
				ma = ri - le + 1;
				cl = le, cr = ri;
			}
		}
	}
	string ans;
	rep(i, tmp)ans.push_back(s[i]);
	string rans = ans; reverse(all(rans));
	for (int j = cl; j <= cr; j++) {
		ans.push_back(t[j]);
	}
	ans += rans;
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	stop
		return 0;
}