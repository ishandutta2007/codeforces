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
const ll mod = 998244353;
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

bool isd[1 << 17];
int num[1 << 17];
void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) {
		char t; cin >> t; a[i] = t - '0';
	}
	rep(i, n) {
		char t; cin >> t; b[i] = t - '0';
	}
	vector<int> cop = a;
	rep(i, n - 1) {
		int d = cop[i] - b[i];
		if (d > 0)isd[i] = true;
		num[i] = abs(d);
		cop[i + 1] -= d;
	}
	if (cop[n - 1] != b[n - 1]) {
		cout << -1 << endl; return;
	}
	ll sum = 0;
	rep(i, n - 1)sum += num[i];
	vector<P> ans;
	queue<int> q;
	rep(i, n - 1) {
		if (isd[i]) {
			if (a[i] > 0 && a[i + 1] > 0)q.push(i);
		}
		else {
			if (a[i] < 9 && a[i + 1] < 9)q.push(i);
		}
	}
	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (isd[i]) {
			if (a[i] == 0 || a[i + 1] == 0)continue;
			int d = min({ a[i],a[i + 1],num[i] });
			a[i] -= d; a[i + 1] -= d; num[i] -= d;
			rep(j, d)ans.push_back({ i + 1,-1 });
		}
		else {
			if (a[i] == 9 || a[i + 1] == 9)continue;
			int d = min({ 9 - a[i],9 - a[i + 1],num[i] });
			a[i] += d; a[i + 1] += d; num[i] -= d;
			rep(j, d)ans.push_back({ i + 1,1 });
		}
		if (ans.size() > 100000)break;

		//add part
		if (i > 0) {
			if (num[i - 1] > 0) {
				if (isd[i - 1]) {
					if (a[i - 1] > 0 && a[i] > 0)q.push(i - 1);
				}
				else {
					if (a[i - 1] < 9 && a[i] < 9)q.push(i - 1);
				}
			}
		}
		if (i + 2 < n) {
			if (num[i + 1] > 0) {
				if (isd[i + 1]) {
					if (a[i + 1] > 0 && a[i + 2] > 0)q.push(i+1);
				}
				else {
					if (a[i + 1] < 9 && a[i + 2] < 9)q.push(i + 1);
				}
			}
		}
	}
	cout << sum << endl;
	int len = min(sum, (ll)100000);
	rep(i, len) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
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