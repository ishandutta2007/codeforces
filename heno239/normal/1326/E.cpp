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


int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct SegT {
private:
	int n; vector<int> node, lazy;
	vector<int> ls, rs;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, mod);
		lazy.resize(2 * n - 1, 0);
		rep(i, sz)node[i+n-1] = 0;
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	int f(int a, int b) {
		return min(a, b);
	}
	void eval(int k, int l, int r) {
		node[k] += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x; eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return mod;
		if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	//a0index
	pair<int, bool> dfs(int a, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a)return { a,false };
		if (a < l) {
			if (node[k] > 0)return { a,false };
		}
		if (k >= n - 1) {
			if (node[k] == 0) {
				return { k-(n-1),true };
			}
			else {
				return { k - (n - 1),false };
			}
		}
		pair<int, bool> cl = dfs(a, 2 * k + 1, l, (l + r) / 2);
		if (cl.second)return cl;
		return dfs(a,2 * k + 2, (l + r) / 2, r);
	}
	int loc(int a) {
		pair<int, bool> p = dfs(a);
		return p.first;
	}
};

int sear(set<int> &st, int loc) {
	if (st.find(loc) != st.end())return loc;
	st.insert(loc);
	auto itr = st.find(loc);
	itr++;
	int res = *itr;
	st.erase(loc);
	return res;
}
void solve() {
	int n; cin >> n;
	vector<int> p(n);
	rep(i, n)cin >> p[i];
	vector<int> trans(n + 1);
	rep(i, n)trans[p[i]] = i;
	vector<int> q(n);
	rep(i, n)cin >> q[i];
	vector<int> ans(n+1);
	ans[0] = n;
	SegT st(n+1);
	st.add(1, trans[n], n);
	set<int> sl; sl.insert(n);
	int cur = n;
	rep(i, n) {
		int loc = q[i] - 1;
		int ri = st.loc(loc);
		//cout << i << " ? " << ri << endl;
		st.add(-1, loc, ri);
		sl.insert(ri);
		while (true) {
			int c = st.query(trans[cur], n);
			if (c == 0) {
				cur--;
				int ri = sear(sl, trans[cur]);
				st.add(1, trans[cur], ri);
				//cout << "! " << cur << " " << ri << endl;
				if (ri != n)sl.erase(ri);
			}
			else break;
		}
		ans[i + 1] = cur;
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}