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

ll mod_pow(ll x, ll n,ll m) {
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
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
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

void solve(){
	int n; cin >> n;
	int x, y; cin >> x >> y;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<queue<int>> q(n+1);
	rep(i, n) {
		a[i]--;
		q[a[i]].push(i);
	}
	vector<int> ans(n);
	int gomi = 0;
	priority_queue<P> que;
	rep(i, n + 1) {
		if (q[i].empty())gomi = i;
		else que.push({ q[i].size(),i });
	}
	rep(i, n)ans[i] = gomi;
	rep(i, x) {
		P p = que.top(); que.pop();
		int col = p.second;
		int loc = q[col].front(); q[col].pop();
		ans[loc] = col;
		if (!q[col].empty()) {
			que.push({ q[col].size(),col });
		}
	}
	int rest = y - x;
	int r = n - x;
	if (que.size()) {
		P p = que.top();
		int num = p.first;
		if (2 * num > r) {
			int mx = 2 * (r - num);
			if (rest > mx) {
				cout << "NO\n"; return;
			}
			que.pop();
			int los = r - 2 * (r - num);
			rep(aa, los) {
				q[p.second].pop();
			}
			if (q[p.second].size()) {
				que.push({ q[p.second].size(),p.second });
			}
		}
	}
	vector<int> cols, locs;
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int col = p.second;
		while (!q[col].empty()) {
			cols.push_back(col);
			locs.push_back(q[col].front());
			q[col].pop();
		}
	}
	if (cols.size()) {
		int sta = 0;
		rep1(i, (int)cols.size() - 1) {
			if (cols[i - 1] != cols[i]) {
				sta = i; break;
			}
		}
		rep(i, rest) {
			int loc = locs[(sta + i) % locs.size()];
			int col = cols[i];
			ans[loc] = col;
		}
	}
	cout << "YES\n";
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i]+1;
	}
	cout << "\n";
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//cout << grandy(2, 3, false, false) << "\n";
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}