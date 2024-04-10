#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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
const ld eps = 1e-12;
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
const int max_n = 1 << 2;
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

struct ste {
	int x, dl, dr;
};
int dist[400][400];
void solve() {
	int n, m; cin >> n >> m;
	rep(i, n)rep(j, n) {
		if (i == j)dist[i][j] = 0;
		else dist[i][j] = mod;
	}
	vector<vector<int>> G(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		dist[a][b] = dist[b][a]=1;
	}
	rep(k, n)rep(i, n)rep(j, n) {
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}
	vector<vector<modint>> ans(n,vector<modint>(n));
	rep(i, n)rep(j, n) {
		if (i == j) {
			modint num = 1;
			rep(v, n) {
				if (v == i)continue;
				int cnt = 0;
				for (int to : G[v]) {
					if (dist[i][to] == dist[i][v] - 1)cnt++;
				}
				num *= cnt;
			}
			ans[i][j] = num;
		}
		else {
			modint num = 1;
			vector<ste> s(n);
			vector<int> v2;
			rep(v, n) {
				int dl = dist[i][v];
				int dr = dist[j][v];
				int dif = dl - dr;
				if (abs(dif) >= dist[i][j]) {
					if (abs(dif) > dist[i][j]) {
						num = 0;
					}
					else {
						if (dif < 0) {
							s[v] = { 0,dl,dr };
						}
						else if (dif > 0) {
							s[v] = { 1,dl,dr };
						}
					}
				}
				else {
					if (dl + dr < dist[i][j]) {
						num = 0;
					}
					else if ((dl + dr - dist[i][j]) % 2) {
						num = 0;
					}
					else if(dl+dr==dist[i][j]){
						s[v] = { 2,dl,dr };
						v2.push_back(dl);
					}
					else {
						s[v] = { 3,dl,dr };
					}
				}
			}
			sort(all(v2));
			rep(i, v2.size()) {
				if (v2[i] != i + 1)num = 0;
			}
			if (num == (modint)0) {
				ans[i][j] = 0; continue;
			}
			/*if (i == 1 && j == 3) {
				cout << "hello\n";
				cout << dist[i][j] << "\n";
				rep(v, n)cout << s[v].x<<" "<<s[v].dl<<" "<<s[v].dr << "\n";
			}*/
			rep(v, n) {
				if (v == i||v==j)continue;
				int cnt = 0;
				if (s[v].x == 0) {
					for (int to : G[v]) {
						if (s[to].x == 0) {
							if (s[to].dl == s[v].dl - 1)cnt++;
						}
					}
				}
				else if (s[v].x == 1) {
					for (int to : G[v]) {
						if (s[to].x == 1) {
							if (s[to].dr == s[v].dr-1)cnt++;
						}
					}
				}
				else if (s[v].x == 2) {
					if (s[v].dl == 1)cnt = 1;
					else {
						for (int to : G[v]) {
							if (s[to].x == 2) {
								if (s[to].dl == s[v].dl - 1)cnt++;
							}
						}
					}
				}
				else {
					for (int to : G[v]) {
						if (s[to].x == 2||s[to].x==3) {
							if (s[to].dl - s[to].dr == s[v].dl - s[v].dr) {
								if (s[to].dl + s[to].dr == s[v].dl + s[v].dr - 2) {
									cnt++;
								}
							}
						}
					}
				}
				num *= cnt;
				/*if (i == 1 && j == 3) {
					cout << "?? " << v << " " << num << "\n";
				}*/
			}
			/*if (i == 4 && j == 5) {
				cout << "hello " << num << "\n";
			}*/
			if (dist[i][j] > 1) {
				int cnt = 0;
				for (int to : G[j]) {
					if (s[to].x == 2 && s[to].dl == s[j].dl - 1)cnt++;
				}
				num *= cnt;
			}
			ans[i][j] = num;
		}
	}
	rep(i, n) {
		rep(j, n) {
			if (j > 0)cout << " ";
			cout << ans[i][j];
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