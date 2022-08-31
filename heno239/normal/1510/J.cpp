#pragma GCC target("avx2")
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
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

bool isok(string s,vector<int> num) {
	int n = s.size();
	int sum = 0;
	rep(i, num.size())sum += num[i];
	sum += num.size() - 1;
	if (sum > n)return false;
	vector<int> al(n,-1), ar(n, -1);
	int cur = 0;
	rep(i, num.size()) {
		rep(j, num[i]) {
			al[cur] = i; cur++;
		}
		cur++;
	}
	cur = n - 1;
	per(i, num.size()) {
		rep(j, num[i]) {
			ar[cur] = i; cur--;
		}
		cur--;
	}
	string t; t.resize(n, '_');
	rep(i, n)if (al[i] == ar[i]&&al[i]>=0)t[i] = '#';
	return s == t;
}

void solve() {
	string s; cin >> s;
	int n = s.size();
	bool exi = false;
	rep(i, n)if (s[i] == '#')exi = true;
	if (!exi) {
		cout << 0 << "\n";
		return;
	}
	vector<int> ans;

	vector<P> v;
	rep(i, n)if(s[i]=='#') {
		int le = i;
		while (i + 1 < n && s[i + 1] == '#')i++;
		v.push_back({ le,i });
	}
	rep(dif, 4) {
		vector<int> num;
		int le = 0;
		rep(j, v.size()) {
			int rest = v[j].first - le - dif;
			while (rest >= 2) {
				if (rest == 3) {
					num.push_back(2);
					rest = 0;
				}
				else {
					num.push_back(1);
					rest -= 2;
				}
			}
			num.push_back(v[j].second - v[j].first + 1 + dif);
			le = v[j].second + 2;
		}
		int rest = n - v.back().second - 2 - dif;
		//rep(i, num.size())cout << num[i] << "\n";

		while (rest > 0) {
			if (rest == 2) {
				num.push_back(2);
				rest = 0;
			}
			else {
				num.push_back(1);
				rest -= 2;
			}
		}
		if (isok(s, num)) {
			ans = num;
		}
	}
	if (ans.empty())cout << -1 << "\n";
	else {
		cout << ans.size() << "\n";
		rep(i, ans.size()) {
			if (i > 0)cout << " ";
			cout << ans[i];
		}
		cout << "\n";
	}

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();

	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}