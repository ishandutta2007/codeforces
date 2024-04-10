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

void queryr() {
	cout << "R" << endl;
}
int tmp = 0;
bool queryq(int id) {
	tmp++;
	//return true;
	cout << "? " << id + 1 << endl;
	char t; cin >> t;
	return t == 'Y';
}

bool yes[1024];
void subsolve(int n, int k,int s) {
	if (k == 1) {
		rep1(len, n - 1) {
			queryr();
			rep(j, len) {
				for (int x = j; x < n; x += len) {
					if (queryq(x))yes[x+s] = true;
				}
			}
		}
		return;
	}
	if (n == k) {
		queryr();
		rep(i, n) {
			if (queryq(i + s))yes[i + s] = true;
		}
		return;
	}
	int d = (n / 2) / (k/2);
	rep(i, d)rep(j, d) {
		queryr();
		rep(x, k/2) {
			int id = i * (k/2) + s + x;
			if (queryq(id))yes[id] = true;
		}
		rep(x, k / 2) {
			int id = j * (k/2) + s +n/2+ x;
			if (queryq(id))yes[id] = true;
		}
	}
	subsolve(n / 2, k, s);
	subsolve(n / 2, k, s+n/2);
}
void solve(int n,int k) {
	tmp = 0;
	//subsolve(n, k, 0);
	int ans = 0;
	if (k == 1) {
		rep1(len, n - 1) {
			rep(j, len) {
				if (j + len >= n)continue;
				queryr();
				for (int x = j; x < n; x += len) {
					if (queryq(x))yes[x] = true;
				}
			}
		}
	}
	else {
		if (k == n) {
			rep(i, n) {
				if (queryq(i))yes[i] = true;
			}
		}
		int d = n / k;
		rep1(len, d-1) {
			rep(s, len) {
				if (s + len >= d)continue;
				queryr();
				for (int x = s; x < d; x += len) {
					rep(i, k) {
						int id = x * k + i;
						if (yes[id])continue;
						if (queryq(id))yes[id] = true;
					}
				}
				queryr();
				for (int x = s; x < d; x += len) {
					rep(i, k) {
						int id = x * k + k - 1 - i;
						if (yes[id])continue;
						if (queryq(id))yes[id] = true;
					}
				}
			}
		}
	}


	rep(i, n)if (!yes[i])ans++;
	cout <<"! "<<ans << endl;
	//cout << tmp << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f(); init();
	//int t; cin >> t; rep(i, t)solve();
	/*for (int n = 1; n <= 1024; n <<= 1) {
		for (int k = 1; k <= n; k <<= 1) {
			int z = 3 * n*n / (2 * k);
			if (z <= 15000) {
				cout << n << " " << k << endl;
				solve(n,k);
				if (tmp > z) {
					cout << n << " " << k << " " << tmp << " " << z << endl;
				}
			}
		}
	}*/
	int n, k; cin >> n >> k;
	solve(n,k);
	//stop
		return 0;
}