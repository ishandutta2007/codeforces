#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
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


struct sparse_table {
private:
	int n;
	int tmp;
	vector<int> ori;
	vector<vector<int>> nodel, noder;
public:
	sparse_table(vector<int> _ori) {
		ori = _ori;
		n = ori.size();
		int cop = n;
		tmp = 0;
		while (cop > 0) {
			tmp++; cop >>= 1;
		}
		nodel.resize(n);
		noder.resize(n);
		rep(i, n) {
			nodel[i].resize(tmp);
			noder[i].resize(tmp);
		}
		rep(i, n) {
			nodel[i][0] = ori[i];
			noder[i][0] = ori[i];
		}
		rep(j, tmp - 1) {
			rep(i, n) {
				if (i + (1 << j) < n) {
					nodel[i][j + 1] = min(nodel[i][j], nodel[i + (1 << j)][j]);
				}
				if (i - (1 << j) >= 0) {
					noder[i][j + 1] = min(noder[i][j], noder[i - (1 << j)][j]);
				}
			}
		}
	}
	//[l,r)
	int query(int l, int r) {
		if (r - l == 0)return mod;
		int len = r - l;
		int x = 1;
		int cnt = 0;
		while (x * 2 <= len) {
			x *= 2;
			cnt++;
		}
		return min(nodel[l][cnt], noder[r - 1][cnt]);
	}
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	sparse_table st(a);

	int x = a[n - 1];
	vector<int> r;
	per(i, n) {
		x = max(x, a[i]);
		r.push_back(x);
	}
	int ma = a[0];
	//[0,i]
	rep(i, n-2) {
		ma = max(ma, a[i]);
		int le = i+1, ri = n+1;
		//[i+1,mid)
		while (ri - le > 1) {
			int mid = (le + ri) / 2;
			int val = st.query(i + 1, mid);
			if (val < ma)ri = mid;
			else le = mid;
		}
		int r1 = le+1;
		le = i+1, ri = n+1;
		while (ri - le > 1) {
			int mid = (le + ri) / 2;
			int val = st.query(i + 1, mid);
			if (val <= ma)ri = mid;
			else le = mid;
		}
		int l1 = le+1;
		int r2 = lower_bound(all(r), ma) - r.begin();
		int l2 = upper_bound(all(r), ma) - r.begin();
		l2 = n - l2;
		r2 = n - r2;

		//cout << i << " " << l1 << " " << l2 << " " << r1 << " " << r2 << "\n";
		l1 = max(l1, l2);
		r1 = min(r1, r2);
		if (l1 < r1) {
			cout << "YES\n";
			cout << i + 1 << " " << l1 - (i+1) << " " << n - l1 << "\n";
			return;
		}
	}
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}