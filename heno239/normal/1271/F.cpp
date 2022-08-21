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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void solve() {
	int a[3], b[3];
	rep(i, 3)cin >> a[i];
	rep(i, 3)cin >> b[i];
	vector<int> d(7);
	rep(i, 7) {
		cin >> d[i];
	}
	int ra[3], rb[3];
	int rd[3];
	reverse(d.begin(), d.end());
	int ans = 0;
	rep(i, d[2] + 1) {
		rep(j, d[4] + 1) {
			rep(k, d[5] + 1) {
				int s = d[2] + d[4] + d[5];
				ra[0] = a[0] - j - k;
				ra[1] = a[1] - i - k;
				ra[2] = a[2] - i - j;
				rb[0] = b[0] - s +d[2]+ j + k;
				rb[1] = b[1] - s +d[4]+ i + k;
				rb[2] = b[2] - s +d[5]+ i + j;

				int mia = min({ ra[0], ra[1], ra[2] });
				int mib = min({ rb[0], rb[1], rb[2] });
				//cout << i << " " << j << " " << k << endl;
				/*if (i == 2 && j == 3 && k == 1) {
					cout << mia << " " << mib << endl;
				}*/
				if (min(mia, mib)<0)continue;
				rd[0] = d[3], rd[1] = d[1], rd[2] = d[0];
				int ma = 0;
				rep(l, 3) {
					rd[l] -= ra[l] - mia;
					rd[l] -= rb[l] - mib;
					ma = max(ma, rd[l]);
				}
				ma = max(ma, 0);
				if (mia + mib < d[6] + ma)continue;
				//cout << rd[0] << " " << rd[1] << " " << rd[2] << endl;
				vector<int> ans(7);
				ans[2] = i, ans[4] = j, ans[5] = k;
				//cout << "! " << k << endl;
				rd[0] = d[3], rd[1] = d[1], rd[2] = d[0];
				rep(l, 3) {
					int m = min(rd[l], ra[l] - mia);
					ans[2-l + (l == 0)] += m; rd[l] -= m;
					m = min(rd[l], rb[l] - mib);
					rd[l] -= m;
				}
				ma = max(ma, 0);
				int m = min(mia, ma);
				rep(l, 3) {
					ans[2 - l + (l == 0)] += min(mia,rd[l]);
				}
				mia -= m;
				m = min(mia, d[6]);
				ans[6] = m;
				reverse(ans.begin(), ans.end());
				rep(l, ans.size()) {
					if (l > 0)cout << " ";
					cout << ans[l];
				}
				cout << endl; return;
			}
		}
	}
	cout << -1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	stop
		return 0;
}