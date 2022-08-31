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
const ld eps = 1e-12;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n, ll m) {
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
using mP = pair<modint, modint>;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

vector<int> merge(vector<int> &l, vector<int> &r) {
	vector<int> res(4,-mod);
	rep(i, 4)rep(j, 4) {
		int sum = l[i] + r[j];
		int nl = i | j;
		res[nl] = max(res[nl], sum);
		if (i& 1) {
			nl = (i ^ 1) | 2 | j;
			res[nl] = max(res[nl], sum);
		}
		if (j & 1) {
			nl = (j ^ 1) | 2 | i;
			res[nl] = max(res[nl], sum);
		}
	}
	return res;
}
void solve() {
	int n, k; cin >> n >> k;
	if (k == 0) {
		cout << 0 << endl; return;
	}
	int al = (1 << n);
	vector<bool> exi(al);
	rep(i, k) {
		int a; cin >> a; a--;
		exi[a] = true;
	}
	vector<int> cnt(al + 1);
	rep(i, al) {
		cnt[i + 1] = cnt[i];
		if (exi[i])cnt[i + 1]++;
	}
	int ans = 1;
	rep(i, al / 2) {
		if (exi[2 * i] || exi[2 * i + 1])ans++;
	}
	vector<vector<int>> dps;
	rep(i, al / 4) {
		int le = 4 * i;
		int ri = 4 * (i + 1);
		int c = cnt[ri] - cnt[le];
		if (c == 0) {
			dps.push_back({ 0,-mod,-mod,-mod });
		}
		else if (c == 1) {
			dps.push_back({ 0,1,2,-mod });
		}
		else {
			dps.push_back({ 0,1,2,3 });
		}
	}
	while (dps.size() >= 2) {
		vector<vector<int>> nexs;
		int len = dps.size();
		rep(j, len / 2) {
			vector<int> dl = dps[2 * j];
			vector<int> dr = dps[2 * j + 1];
			vector<int> dm = merge(dl, dr);
			dm[1]++;
			dm[2] += 2;
			dm[3] += 3;
			nexs.push_back(dm);
		}
		swap(dps, nexs);
	}
	int ma = 0;
	rep(i, 4)ma = max(ma, dps[0][i]);
	ans += ma;
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}