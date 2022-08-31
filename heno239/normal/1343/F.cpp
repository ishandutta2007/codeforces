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

vector<int> simulate(vector<vector<int>> v, int ban) {
	int len = v.size(); int n = len + 1;

	vector<int> res;
	vector<pair<int,vector<int>>> memo;
	rep(i, n - 1) {
		vector<int> cnt(n, 0);
		rep(j, v.size()) {
			for (int id : v[j]) {
				cnt[id]++;
			}
		}
		int nex = -1;
		rep(j, n)if (j != ban && cnt[j] == 1) {
			nex = j;
		}
		//cout << nex << " hello\n";
		if (nex < 0)return {};
		res.push_back(nex);
		int chk;
		rep(j, v.size()) {
			for (int id : v[j]) {
				if (id == nex) {
					chk = j;
				}
			}
		}
		memo.push_back({ n - 1 - i,v[chk] });
		v.erase(v.begin() + chk);
	}
	int las = n * (n - 1) / 2;
	for (int id : res)las -= id;
	res.push_back(las);
	reverse(all(res));
	rep(i, memo.size()) {
		vector<int> c;
		int len = memo[i].second.size();
		rep(j, len) {
			int loc = memo[i].first - j;
			c.push_back(res[loc]);
		}
		sort(all(c));
		if (c != memo[i].second)return {};
	}
	return res;
}
void solve() {
	int n; cin >> n;
	vector<vector<int>> v(n-1);
	rep(i, n - 1) {
		int len; cin >> len;
		v[i].resize(len);
		rep(j, len) {
			cin >> v[i][j];
			v[i][j]--;
		}
	}
	rep(i,n){
		vector<int> s = simulate(v, i);
		//cout << s.size() << "\n";
		if (s.size() == n) {
			rep(i, n) {
				if (i > 0)cout << " ";
				cout << s[i]+1;
			}
			cout << "\n";
			return;
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//experi();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	stop
		return 0;
}