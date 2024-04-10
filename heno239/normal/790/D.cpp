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
	a %= m;
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


void solve() {
	int n; cin >> n;
	vector<vector<ll>> v(2, vector<ll>(n));
	rep(i, 2)rep(j, n)cin >> v[i][j];
	vector<pair<P, int>> up, dow;

	vector<int> r0(n, mod), r1(n, mod), r2(n, mod);
	map<ll, int> mp;
	ll sum = 0;
	mp[sum] = 0;
	rep(j, n) {
		sum += v[0][j];
		if (mp.find(sum) != mp.end()) {
			//up.push_back({ {j,mp[sum]},-2 });
			r0[mp[sum]] = j;
		}
		mp[sum] = j + 1;
	}

	mp.clear(); sum = 0;
	mp[sum] = 0;
	rep(j, n) {
		sum += v[1][j];
		if (mp.find(sum) != mp.end()) {
			r1[mp[sum]] = j;
		}
		mp[sum] = j + 1;
	}
	mp.clear(); sum = 0;
	mp[sum] = 0;
	int tmp = 0;
	rep(j, n) {
		sum += v[0][j] + v[1][j];
		if (mp.find(sum) != mp.end()) {
			r2[mp[sum]] = j;
			tmp++;
		}
		mp[sum] = j + 1;
	}

	vector<int> to0(n+1,mod), to1(n+1,mod), to2(n+1,mod);
	int ri = mod;
	per(i, n) {
		ri = min(ri, r0[i]);
		to0[i] = ri;
	}
	ri = mod;
	per(i, n) {
		ri = min(ri, r1[i]);
		to1[i] = ri;
	}
	ri = mod;
	per(i, n) {
		ri = min(ri, r2[i]);
		to2[i] = ri;
	}

	vector<P> vs;
	vs.push_back({ 0,0 });
	int ans = 0;
	while (vs.size()) {
		vector<P> nex;
		for (P p : vs) {
			int l = p.first;
			int r = p.second;
			//cout << ans << " " << l << " " << r << "\n";
			int nl = to0[l] + 1;
			int nr = to1[r] + 1;
			if (nl > n&&nr > n) {
				//
			}
			else if (nl > n) {
				nex.push_back({ l,nr });
			}
			else if (nr > n) {
				nex.push_back({ nl,r });
			}
			else {
				if (l < r&&nl < nr) {
					nex.push_back({ nl,r });
				}
				else if (l > r&&nl > nr) {
					nex.push_back({ l,nr });
				}
				else {
					nex.push_back({ l,nr });
					nex.push_back({ nl,r });

				}
			}
			if (max(l, r) < n) {
				int to = to2[max(l, r)] + 1;
				if (to <= n) {
					nex.push_back({ to,to });
				}
			}
		}
		sort(all(nex));
		vs.clear();
		int le = mod;
		rep(i, nex.size()) {
			if (le > nex[i].second) {
				vs.push_back(nex[i]);
				le = nex[i].second;
			}
		}
		ans++;
	}
	cout << ans - 1 << "\n";
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