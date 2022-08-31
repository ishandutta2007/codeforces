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

const int max_n = 500;
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


//
//
//
//
//


bool exi[50][2500];
modint dp[51][2500];
modint rdp[51][2501];

modint num[2500][51];
void solve() {
	int n; cin >> n;
	vector<ll> l(n), r(n);

	rep(i, n) {
		cin >> l[i] >> r[i];
	}
	vector<LP> seg;
	rep(i, n) {
		vector<LP> nex;
		ll le = l[i], ri = r[i] + 1;
		for (LP p : seg) {
			if (p.second <= l[i]) {
				nex.push_back(p);
			}
			else if (p.first >= r[i]+1) {
				nex.push_back(p);
			}
			else {
				if (p.first < le) {
					nex.push_back({ p.first,le });
				}
				else {
					if (le != p.first)nex.push_back({ le,p.first });
					le = p.first;
				}
				if (p.second < ri) {
					if (le != p.second)nex.push_back({ le,p.second });
					le = p.second;
					//if(p.second!=ri)nex.push_back({ p.second,ri });
				}
				else {
					if (le != ri)nex.push_back({ le,ri });
					if (ri != p.second)nex.push_back({ ri,p.second });
					le = ri;
				}
			}

		}
		if (le != ri)nex.push_back({ le,ri });
		sort(all(nex));
		nex.erase(unique(all(nex)), nex.end());
		swap(nex, seg);
	}
	seg.push_back({ INF,INF + 1 });
	rep(i, n) {
		rep(j, seg.size()) {
			if (l[i] <= seg[j].first&&seg[j].second <= r[i] + 1)exi[i][j] = true;
		}
	}
	int len = seg.size();
	/*rep(j, len) {
	cout << seg[j].first << " " << seg[j].second << endl;
	}*/
	rep(j, len) {
		Rep(k, j + 1, len) {
			ll ma = max(seg[j].first, seg[k].first);
			ll mi = min(seg[j].second, seg[k].second);
			ll len = (mi - ma);
			//cout << j << " " << k << endl;
			assert(len <= 0);
		}
	}
	dp[0][len - 1] = 1;
	rep(j, len) {
		modint w = seg[j].second - seg[j].first;
		for (int l = 1; l <= n; l++) {
			num[j][l] = 1;
			for (modint i = 1; (int)i <= l; i += 1) {
				//(w+l-1,l)
				num[j][l] = num[j][l] * (w + (modint)l - i);
				num[j][l] = num[j][l] / i;
			}
		}

	}
	rep(i, n) {
		rep(j, len)rdp[i][j + 1] = rdp[i][j] + dp[i][j];
		modint leng = r[i] - l[i] + 1;
		rep(j, len) {
			if (!exi[i][j])continue;
			modint w = seg[j].second - seg[j].first;

			modint b = 1;

			for (int to = i; to < n; to++) {
				if (!exi[to][j])break;
				modint s = num[j][to - i + 1];
				b = b * (modint)(r[to] - l[to] + 1);
				s = s / b;

				dp[to + 1][j] += (rdp[i][len] - rdp[i][j + 1])*s;
			}
		}
	}
	modint ans = 0;
	rep(j, len)ans += dp[n][j];
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f(); init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}