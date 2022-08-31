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
const ld eps = 1e-12;
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m) {
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

const int max_n = 1 << 22;
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<modint> memo(n + 1);
	rep(i, n + 1) {
		memo[i] = fact[m-1+i]*factinv[i];
	}
	vector<modint> rmemo(n + 2);
	rep(i, n + 1) {
		rmemo[i + 1] = rmemo[i] + memo[i];
	}
	vector<modint> smemo(n + 2);
	smemo[0] = 0;
	rep1(i, n) {
		smemo[i] = smemo[i-1] + rmemo[i];
	}
	vector<modint> ex(n+1);
	ex[n] = 0;
	modint ssum = 0;
	per(i, n) {
		modint sum = 0;
		modint cur = 0;
		sum += fact[i] * (modint)m * factinv[i + m] * smemo[i];
		sum += fact[n - i] * (modint)m * factinv[n - i + m] * smemo[n - i];
		modint c = fact[n - i] * (modint)m * factinv[n - i + m];
		cur = c * fact[m - 1 + n - i] * factinv[n - i];
		sum += c*ssum;

		/*modint c = fact[m] / fact[m + n - i];
		for (int j = 0; j <= n - i; j++) {
			modint c = fact[n - i] * fact[m] / fact[n - i + m] * comb(m - 1 + n - i - j, n - i - j);
			sum += (modint)j * c;
			if (j == 0) {
				cur += c;
			}
			else {
				sum += c * ex[i + j];
			}
		}*/
		//sum += c * rmemo[n - i + 1];
		/*for (int x = 0; x <= n - i; x++) {
			if (x == 0) {
				cur += c * fact[x];
			}
			else {
				sum += c * fact[x] * ex[x + i];
			}
		}*/
		sum += 1;
		//cout << sum << " " << cur << "\n";
		ex[i] = sum / ((modint)1 - cur);

		ssum += fact[m - 1 + n - i] * factinv[n - i] * ex[i];
	}
	//cout << ex[1] << "\n";
	cout << ex[0] << "\n";
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init_f();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}