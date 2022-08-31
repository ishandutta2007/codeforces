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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;

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
const ld eps = 1e-4;
const ld pi = acosl(-1.0);

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
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
const int max_n = 1 << 20;
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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

vector<vector<int>> mk(vector<int> a, vector<int> b) {
	int n = a.size();
	vector<vector<int>> res;
	int ev = -1;
	rep(i, n)if (b[i] % 2 == 0)ev = i;
	if (n == 1) {
		if (a[0] == 0) {
			rep(i, b[0]) {
				res.push_back({ i });
			}
		}
		else {
			per(i, b[0]) {
				res.push_back({ i });
			}
		}
	}
	else if (n == 2) {
		if (b[0] % 2 == 0 || b[1] % 2 == 0) {
			bool sw = false;
			if (b[1] % 2 == 0) {
				sw = true;
				swap(a[0], a[1]);
				swap(b[0], b[1]);
			}
			rep(i, b[0]) {
				if (i % 2 == 0) {
					for (int j = 1; j < b[1]; j++)res.push_back({ i,j });
				}
				else {
					for (int j = b[1] - 1; j >= 1; j--)res.push_back({ i,j });
				}
			}
			for (int i = b[0] - 1; i >= 0; i--)res.push_back({ i,0 });
			if (sw) {
				rep(i, res.size()) {
					swap(res[i][0], res[i][1]);
				}
			}
		}
		else {
			bool sw = false;
			if (a[1] == 0) {
				sw = true;
				swap(a[0], a[1]);
				swap(b[0], b[1]);
			}
			if (a[0] == 0) {
				for (int j = a[1]; j >= 0; j--)res.push_back({ 0,j });
				for (int j = 0; j <= a[1]; j++) {
					if (j % 2 == 0) {
						for (int i = 1; i < b[0]; i++) {
							res.push_back({ i,j });
						}
					}
					else {
						for (int i = b[0] - 1; i >= 1; i--) {
							res.push_back({ i,j });
						}
					}
				}
				for (int i = b[0] - 1; i >= 0; i--) {
					if ((b[0] - 1 - i) % 2 == 0) {
						for (int j = a[1] + 1; j < b[1]; j++) {
							res.push_back({ i,j });
						}
					}
					else {
						for (int j = b[1] - 1; j > a[1]; j--) {
							res.push_back({ i,j });
						}
					}
				}
				if (sw) {
					rep(i, res.size()) {
						swap(res[i][0], res[i][1]);
					}
				}
			}
			else {
				if (a[0] % 2 == 0) {
					for (int j = a[1]; j < b[1]; j++)res.push_back({ a[0],j });
					for (int j = b[1] - 1; j >= a[1]; j--) {
						if (j % 2 == 0) {
							for (int i = a[0] - 1; i >= 0; i--)res.push_back({ i,j });
						}
						else {
							for (int i = 0; i < a[0]; i++)res.push_back({ i,j });
						}
					}
					for (int i = 0; i <= a[0]; i++) {
						if (i % 2 == 0) {
							for (int j = a[1] - 1; j >= 0; j--)res.push_back({ i,j });
						}
						else {
							for (int j = 0; j < a[1]; j++)res.push_back({ i,j });
						}
					}
					for (int i = a[0] + 1; i < b[0]; i++) {
						if (i % 2 == 0) {
							for (int j = b[1] - 1; j >= 0; j--)res.push_back({ i,j });
						}
						else {
							for (int j = 0; j < b[1]; j++)res.push_back({ i,j });
						}
					}
				}
				else {
					for (int i = a[0]; i >= 0; i--) {
						if (i % 2 == 0) {
							for (int j = b[1] - 1; j >= a[1]; j--)res.push_back({ i,j });
						}
						else {
							for (int j = a[1]; j < b[1]; j++)res.push_back({ i,j });
						}
					}
					for (int j = a[1] - 1; j >= 0; j--) {
						if (j % 2 == 0) {
							for (int i = 0; i <= a[0]; i++)res.push_back({ i,j });
						}
						else {
							for (int i = a[0]; i >= 0; i--)res.push_back({ i,j });
						}
					}
					for (int i = a[0] + 1; i < b[0]; i++) {
						if (i % 2 == 0) {
							for (int j = 0; j < b[1]; j++)res.push_back({ i,j });
						}
						else {
							for (int j = b[1] - 1; j >= 0; j--)res.push_back({ i,j });
						}
					}
				}
			}
		}
	}
	else {
		if (ev >= 0) {
			vector<int> na, nb;
			vector<int> trans(n - 1);
			rep(i, n)if (ev != i) {
				trans[na.size()] = i;
				na.push_back(0);
				nb.push_back(b[i]);
			}
			vector<vector<int>> v = mk(na, nb);
			for (int i = 0; i < b[ev]; i++) {
				if (i % 2 == 0) {
					for (int j = 1; j < v.size(); j++) {
						vector<int> cur(n);
						rep(k, v[j].size())cur[trans[k]] = v[j][k];
						cur[ev] = i;
						res.push_back(cur);
					}
				}
				else {
					for (int j = v.size() - 1; j > 0; j--) {
						vector<int> cur(n);
						rep(k, v[j].size())cur[trans[k]] = v[j][k];
						cur[ev] = i;
						res.push_back(cur);
					}
				}
			}
			for (int i = b[ev] - 1; i >= 0; i--) {
				vector<int> cur(n, 0);
				rep(k, v[0].size())cur[trans[k]] = v[0][k];
				cur[ev] = i;
				res.push_back(cur);
			}
		}
		else {
			if (n == 3) {
				int chk = -1;
				rep(i, n)if (a[i] % 2 == 0)chk = i;
				vector<int> na, nb;
				vector<int> trans(n - 1);
				rep(i, n)if (chk != i) {
					trans[na.size()] = i;
					na.push_back(a[i]);
					nb.push_back(b[i]);
				}
				vector<vector<int>> v = mk(na, nb);
				for (int i = a[chk]; i >= 0; i--) {
					if (i % 2 == 0) {
						for (int j = 0; j < v.size() - 1; j++) {
							vector<int> cur(n);
							rep(k, v[j].size())cur[trans[k]] = v[j][k];
							cur[chk] = i;
							res.push_back(cur);
						}
					}
					else {
						for (int j = v.size() - 2; j >= 0; j--) {
							vector<int> cur(n);
							rep(k, v[j].size())cur[trans[k]] = v[j][k];
							cur[chk] = i;
							res.push_back(cur);
						}
					}
				}
				for (int i = 0; i <= a[chk]; i++) {
					int j = v.size() - 1;
					vector<int> cur(n);
					rep(k, v[j].size())cur[trans[k]] = v[j][k];
					cur[chk] = i;
					res.push_back(cur);
				}
				for (int i = a[chk] + 1; i < b[chk]; i++) {
					if (i % 2 == 0) {
						for (int j = 0; j < v.size(); j++) {
							vector<int> cur(n);
							rep(k, v[j].size())cur[trans[k]] = v[j][k];
							cur[chk] = i;
							res.push_back(cur);
						}
					}
					else {
						for (int j = v.size() - 1; j >= 0; j--) {
							vector<int> cur(n);
							rep(k, v[j].size())cur[trans[k]] = v[j][k];
							cur[chk] = i;
							res.push_back(cur);
						}
					}
				}
			}
			else {
				int chk1 = -1, chk2 = -1;
				rep(i, n)Rep(j, i + 1, n) {
					if ((a[i] + a[j]) % 2 == 0) {
						chk1 = i, chk2 = j;
					}
				}
				vector<int> na, nb;
				vector<int> trans(n - 1);
				rep(i, n)if (i!=chk1&&i!=chk2) {
					trans[na.size()] = i;
					na.push_back(a[i]);
					nb.push_back(b[i]);
				}
				vector<vector<int>> rv = mk(na, nb);
				vector<vector<int>> lv = mk({ a[chk1],a[chk2] }, { b[chk1],b[chk2] });
				rep(i, lv.size()) {
					if (i % 2 == 0) {
						for (int j = 0; j < rv.size(); j++) {
							vector<int> cur(n);
							rep(k, rv[j].size())cur[trans[k]] = rv[j][k];
							cur[chk1] = lv[i][0];
							cur[chk2] = lv[i][1];
							res.push_back(cur);
						}
					}
					else {
						for (int j = rv.size() - 1; j >= 0;j--) {
							vector<int> cur(n);
							rep(k, rv[j].size())cur[trans[k]] = rv[j][k];
							cur[chk1] = lv[i][0];
							cur[chk2] = lv[i][1];
							res.push_back(cur);
						}
					}
				}
			}
		}
	}
	return res;
}
bool can(vector<int> a, vector<int> b) {
	int n = a.size();
	if (n == 1) {
		if (a[0] != 0 && a[0] != b[0] - 1) {
			return false;
		}
	}
	else {
		bool ev = false;
		rep(i, n)if (b[i] % 2 == 0)ev = true;
		int x = 0;
		rep(i, n)x += a[i];
		if (!ev && (x % 2))return false;
	}
	return true;
}
void incdec(vector<int> cur, vector<int> nex) {
	int tmp = 0;
	rep(i, cur.size())if (cur[i] != nex[i]) {
		if (cur[i] + 1 == nex[i]) {
			cout << "inc " << i + 1 << "\n";
		}
		else if(cur[i]-1==nex[i]){
			cout << "dec " << i + 1 << "\n";
		}
		else {
			tmp = 100;
		}
		tmp++;
	}
	assert(tmp == 1);
}
void solve() {
	int n; cin >> n;
	vector<int> b(n); rep(i, n)cin >> b[i];
	vector<int> a(n); rep(i, n) {
		cin >> a[i]; a[i]--;
	}
	if (!can(a, b)) {
		cout << "No\n"; return;
	}
	vector<vector<int>> v = mk(a, b);
	int dif = 0;
	rep(i, n) {
		dif += abs(v[0][i] - v.back()[i]);
	}
	if (dif == 1) {
		int s = -1;
		rep(i, v.size())if (v[i] == a)s = i;
		assert(s >= 0);
		rep(i, s)v.push_back(v[i]);
		v.erase(v.begin(), v.begin() + s);
		cout << "Cycle\n";
		rep(i, v.size()) {
			int ni = (i + 1 == v.size() ? 0 : i + 1);
			incdec(v[i], v[ni]);
		}
	}
	else {
		cout << "Path\n";
		rep(i, v.size()-1) {
			incdec(v[i], v[i + 1]);
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(8);
	//init_f();
	//init();
	//while(true)
	//expr();
	//init();
	//int t; cin >> t; rep(i,t)
	solve();
	return 0;
}