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
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
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

const int max_n = 1 << 19;
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

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}
const int sz = 20;
struct wavelet_matrix {
private:
	vector<bool> b[sz];
	vector<int> cntone[sz];
	vector<int> nex[sz];

	vector<P> le[sz], ri[sz];

	vector<int> las;
public:
	void init(vector<int> v) {
		int n = v.size();

		per(i, sz) {
			vector<P> v0, v1;
			rep(j, n) {
				cntone[i][j + 1] = cntone[i][j];
				if (v[j] & (1 << i)) {
					b[i][j] = true;
					cntone[i][j + 1]++;
					v1.push_back({ v[j],j });
				}
				else {
					b[i][j] = false;
					v0.push_back({ v[j],j });
				}
			}

			P pre = { 0,0 };
			rep(j, n) {
				le[i][j] = pre;
				if (b[i][j])pre.second = j;
				else pre.first = j;
			}
			le[i][n] = pre;
			pre = { n,n };
			per(j, n) {
				if (b[i][j])pre.second = j;
				else pre.first = j;
				ri[i][j] = pre;
			}
			v.clear();
			rep(j, v0.size()) {
				nex[i][v0[j].second] = j; v.push_back(v0[j].first);
			}
			rep(j, v1.size()) {
				nex[i][v1[j].second] = j + v0.size();
				v.push_back(v1[j].first);
			}
		}
		las = v;
	}
	wavelet_matrix(vector<int> v) {
		int n = v.size();
		rep(i, sz) {
			b[i].resize(n);
			cntone[i].resize(n + 1);
			nex[i].resize(n);
			le[i].resize(n + 1);
			ri[i].resize(n);
		}

		per(i, sz) {
			vector<P> v0, v1;
			rep(j, n) {
				cntone[i][j + 1] = cntone[i][j];
				if (v[j] & (1 << i)) {
					b[i][j] = true;
					cntone[i][j + 1]++;
					v1.push_back({ v[j],j });
				}
				else {
					b[i][j] = false;
					v0.push_back({ v[j],j });
				}
			}

			P pre = { 0,0 };
			rep(j, n) {
				le[i][j] = pre;
				if (b[i][j])pre.second = j;
				else pre.first = j;
			}
			le[i][n] = pre;
			pre = { n,n };
			per(j, n) {
				if (b[i][j])pre.second = j;
				else pre.first = j;
				ri[i][j] = pre;
			}
			v.clear();
			rep(j, v0.size()) {
				nex[i][v0[j].second] = j; v.push_back(v0[j].first);
			}
			rep(j, v1.size()) {
				nex[i][v1[j].second] = j + v0.size();
				v.push_back(v1[j].first);
			}
		}
		las = v;
	}
	//[l,r)
	int take_kth(int k, int l, int r) {
		per(i, sz) {
			int c = cntone[i][r] - cntone[i][l];
			if (r - l - c < k) {
				k -= r - l - c;
				l = nex[i][ri[i][l].second];
				r = nex[i][le[i][r].second] + 1;
			}
			else {
				l = nex[i][ri[i][l].first];
				r = nex[i][le[i][r].first] + 1;
			}
		}
		return las[l];
	}

	//////////////not veryfied




	//number of >=k in [l,r)
	int number_upk(int k, int l, int r) {
		int res = 0;
		per(i, sz) {
			if (k & (1 << i)) {
				l = ri[i][l].second;
				r = le[i][r].second;
				if (l > r)break;
				l = nex[i][l];
				r = nex[i][r] + 1;
			}
			else {
				res += cntone[i][r] - cntone[i][l];
				l = ri[i][l].first;
				r = le[i][r].first;
				if (l > r)break;
				l = nex[i][l];
				r = nex[i][r] + 1;
			}
		}
		if (l < r)res += r - l;
		return res;
	}
	//number of <=k in [l,r)
	int number_dwk(int k, int l, int r) {
		int res = 0;
		per(i, sz) {
			if (k & (1 << i)) {
				res += r - l;
				res -= cntone[i][r] - cntone[i][l];
				l = ri[i][l].second;
				r = le[i][r].second;
				if (l > r)break;
				l = nex[i][l];
				r = nex[i][r] + 1;
			}
			else {
				l = ri[i][l].first;
				r = le[i][r].first;
				if (l > r)break;
				l = nex[i][l];
				r = nex[i][r] + 1;
			}
		}
		if (l < r)res += r - l;
		return res;
	}
};

const int sup = 1000000;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> vx = { 0,sup }, vy = { 0,sup };
	vector<int> y(n), lx(n), rx(n);
	rep(i, n) {
		cin >> y[i] >> lx[i] >> rx[i];
		vx.push_back(lx[i]);
		vx.push_back(rx[i]);
		vy.push_back(y[i]);
	}
	vector<int> x(m), ly(m), ry(m);
	rep(i, m) {
		cin >> x[i] >> ly[i] >> ry[i];
		vx.push_back(x[i]);
		vy.push_back(ly[i]);
		vy.push_back(ry[i]);
	}
	sort(all(vx)); vx.erase(unique(all(vx)), vx.end());
	sort(all(vy)); vy.erase(unique(all(vy)), vy.end());
	auto calc = [&](vector<int>& v, int t)->int {
		return lower_bound(all(v), t) - v.begin();
	};
	rep(i, n) {
		lx[i] = calc(vx, lx[i]);
		rx[i] = calc(vx, rx[i]);
		y[i] = calc(vy, y[i]);
	}
	rep(i, m) {
		x[i]=calc(vx, x[i]);
		ly[i]=calc(vy, ly[i]);
		ry[i] = calc(vy, ry[i]);
	}
	vector<int> ori(vx.size(), 0);
	rep(i, m)if (ly[i] == 0) {
		ori[x[i]] = ry[i];
	}
	ll ans = 1;
	wavelet_matrix mt(ori);
	rep(i, n) {
		ans += mt.number_upk(y[i], lx[i], rx[i]+1);
	}
	fill(all(ori), vy.size()-1);
	rep(i, m)if (ry[i] == vy.size()-1 && ly[i] > 0) {
		ori[x[i]] = ly[i];
	}
	mt.init(ori);
	rep(i, n) {
		ans += mt.number_dwk(y[i], lx[i], rx[i]+1);
	}
	rep(i, n)if (lx[i] == 0 && rx[i] == vx.size()-1)ans++;
	rep(i, m)if (ly[i] == 0 && ry[i] == vy.size()-1)ans++;
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}