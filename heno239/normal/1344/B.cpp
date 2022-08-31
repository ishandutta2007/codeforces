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

char mp[1000][1000];
bool used[1000][1000];

bool valid(vector<P> &v) {
	sort(all(v));
	rep(i, v.size()) {
		if (i > 0 && v[i].first == v[i - 1].first) {
			if (v[i].second != v[i - 1].second + 1)return false;
		}
	}
	rep(i, v.size())swap(v[i].first, v[i].second);
	sort(all(v));
	rep(i, v.size()) {
		if (i > 0 && v[i].first == v[i - 1].first) {
			if (v[i].second != v[i - 1].second + 1)return false;
		}
	}
	rep(i, v.size())swap(v[i].first, v[i].second);
	return true;
}
void solve() {
	int h, w; cin >> h >> w;
	rep(i, h)rep(j, w) {
		cin >> mp[i][j];
	}

	rep(i, h) {
		int las = -1;
		rep(j, w) {
			if (mp[i][j] == '#') {
				if (las < 0)las = j;
				else {
					if (las + 1 != j) {
						cout << -1 << "\n"; return;
					}
					las = j;
				}
			}
		}
	}
	rep(j, w) {
		int las = -1;
		rep(i, h) {
			if (mp[i][j] == '#') {
				if (las < 0)las = i;
				else {
					if (las + 1 != i) {
						cout << -1 << "\n"; return;
					}
					las = i;
				}
			}
		}
	}
	int ans = 0;
	vector<bool> exih(h, false), exiw(w, false);
	rep(i, h)rep(j, w) {
		if (used[i][j])continue;
		if (mp[i][j] == '.')continue;
		vector<P> v;
		queue<P> q; q.push({ i,j });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			v.push_back({ x,y });
			used[x][y] = true;
			q.pop();
			rep(d, 4) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 0 || nx >= h || ny < 0 || ny == w)continue;
				if (used[nx][ny])continue;
				if (mp[nx][ny] == '.')continue;
				used[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		/*if (!valid(v)) {

			cout << -1 << "\n"; return;
		}*/
		for (P p : v) {
			exih[p.first] = true;
			exiw[p.second] = true;
		}
		ans++;
	}

	//south valid
	int ch = 0, cw = 0;
	rep(i, h)if (!exih[i])ch++;
	rep(i, w)if (!exiw[i])cw++;
	bool b = true;
	if (ch > 0 && cw == 0)b = false;
	if (ch == 0 && cw > 0)b = false;
	if (!b) {
		cout << -1 << "\n";
	}
	else {
		cout << ans << "\n";
	}
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