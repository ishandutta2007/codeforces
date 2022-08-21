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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
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

const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init() {
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

const int mn = 100000;
vector<int> ch[mn+1];
int u[mn + 1];
bool isp[mn + 1];
void init_ch() {
	fill(isp+2, isp + mn + 1, true);
	fill(u + 1, u + mn + 1, 1);
	for (int i = 2; i <= mn; i++) {
		if (!isp[i])continue;
		u[i] = -u[i];
		for (int j = 2 * i; j <= mn; j += i) {
			if ((j/i) % i == 0) {
				u[j] = 0;
			}
			u[j] = -u[j];
			isp[j] = false;
		}
	}
	for (int i = 1; i <= mn; i ++) {
		for (int j = i; j <= mn; j += i) {
			ch[j].push_back(i);
		}
	}
}

vector<int> z[mn + 1];

int cnt[mn + 1];

int calc(int x) {
	int res = 0;
	for (auto d : ch[x]) {
		res += u[d] * cnt[d];
	}
	return res;
}
void update(int x, int a) {
	for (auto d : ch[x]) {
		cnt[d] += a;
	}
}


void solve() {
	init_ch();
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(all(a),greater<int>());
	a.erase(unique(all(a)), a.end());
	ll ans = a[0];
	rep(i, a.size()) {
		for (int d : ch[a[i]]) {
			z[d].push_back(a[i] / d);
		}
	}
	rep1(i, mn) {
		stack<int> st;
		for (auto x : z[i]) {
			while (calc(x) > 0) {
				update(st.top(), -1);
				ans = max(ans, (ll)x*st.top()*i);
				st.pop();
			}
			st.push(x); update(x, 1);
		}
		while (st.size()) {
			update(st.top(), -1); st.pop();
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}