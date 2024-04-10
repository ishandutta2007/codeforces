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
const ld eps = 1e-12;
const ld pi = acos(-1.0);

void chmin(int &a, int b) {
	a = min(a, b);
}
void chmax(int &a, int b) {
	a = max(a, b);
}
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

int gcd(int a, int b) {
	a = abs(a), b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}
void solve() {
	int n, k; cin >> n >> k;
	vector<int> x(n), y(n);
	vector<pair<P, ld>> vs;
	rep(i, n) {
		cin >> x[i] >> y[i];
		int g = gcd(x[i], y[i]);
		if (g == 0)continue;
		ld d = sqrtl((ll)x[i] * x[i] + (ll)y[i] * y[i]);
		x[i] /= g; y[i] /= g;
		vs.push_back({ {x[i],y[i]},d });
	}
	sort(all(vs));
	vector<vector<ld>> ds;
	rep(i, vs.size()) {
		vector<ld> c;
		c.push_back(vs[i].second);
		while (i + 1 < vs.size() && vs[i].first == vs[i + 1].first) {
			i++; c.push_back(vs[i].second);
		}
		ds.push_back(c);
	}
	ds.push_back({ 0 });
	
	vector<vector<ld>> rds(ds.size());
	rep(i, ds.size()) {
		rds[i].resize(ds[i].size() + 1);
		rep(j, ds[i].size()) {
			rds[i][j + 1] = rds[i][j] + ds[i][j];
		}
	}
	vector<vector<ld>> oris(ds.size());
	rep(i, ds.size()) {
		oris[i].resize(ds[i].size() + 1);
		oris[i][0] = 0;
		rep1(j, (int)ds[i].size()) {
			oris[i][j] = oris[i][j - 1];
			oris[i][j] += rds[i][ds[i].size()] - rds[i][ds[i].size() - j];
			oris[i][j] -= j * ds[i][ds[i].size() - j];
		}
	}
	vector<vector<ld>> pos(ds.size());
	vector<pair<ld, P>> ss;
	rep(i, ds.size()) {

		int len = ds[i].size();
		pos[i].resize(len + 1);
		rep(j, len+1) {
			if (n - len + j < k) {
				pos[i][j] = INF;
			}
			else {
				if (j > k)pos[i][j] = -INF;
				else {
					pos[i][j] = (k - j)*(rds[i][len] - rds[i][len - j]) + oris[i][j];
				}
			}
			if (j > 0) {
				if (pos[i][j - 1] == INF) {
					ss.push_back({ pos[i][j],{i,j} });
				}
				else {
					ss.push_back({ pos[i][j] - pos[i][j - 1],{i,j} });
				}
			}
		}
	}
	sort(all(ss), greater<pair<ld, P>>());

	vector<int> ts(ds.size(),0);
	int cop = k;
	rep(i, ss.size()) {
		P p = ss[i].second;
		int ad = p.second - ts[p.first];
		ad = max(ad, 0);
		if (cop >=ad) {
			ts[p.first] = max(ts[p.first], p.second);
			cop -= ad;
		}
	}
	/*rep(i, ds.size()) {
		cout << "start\n";
		rep(j, ds[i].size()) {
			cout << ds[i][j] << " ";
		}
		cout << "\n";
		rep(j, ds[i].size() + 1) {
			cout << pos[i][j] <<" ";
		}
		cout << " \n";
		cout << "end\n";
	}*/
	ld sum = 0;
	rep(i, ds.size()) {
		sum += pos[i][ts[i]];
		//cout << i << " ! " << ts[i] << "\n";
	}
	ld ans = sum;

	vector<ld> alpos(ds.size()+1);
	rep(i, ds.size()) {
		alpos[i + 1] = alpos[i] + pos[i][ds[i].size()];
	}
	rep(i, ds.size()) {
		int len = ds[i].size();
		if (n-len<k) {
			int le = n - len;
			int rest = k - le;
			int cl = 0, cr = rest;
			int mid = k/ 2;
			if (le < mid) {
				cl = mid - le;
				cr = rest - cl;


				vector<ld> uses;
				rep(j, cl) {
					uses.push_back(ds[i][j]);
				}
				rep(j, cr) {
					uses.push_back(ds[i][len - cr + j]);
				}

				ld sum = 0;
				ld csum = 0;
				int tmp = 0;
				per(j, (int)uses.size()) {
					tmp++;
					csum += uses[j];
					sum += csum - tmp * uses[j];
				}
				sum += csum * (n - len);
				sum += alpos.back() - pos[i][len];

				//cout << i << " ? " <<" "<<cl<<" "<< sum << "\n";
				ans = max(ans, sum);
			}
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	solve();
	stop
		return 0;
}