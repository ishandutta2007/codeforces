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

const int max_n = 1 << 10;
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


struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = mod;
public:
	SegT(vector<int> v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	int f(int a, int b) {
		return min(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	int searchleft(int k, int x) {
		k += sz - 1;
		while (k > 0) {
			int pre = k;
			k = (k - 1) / 2;
			if (2 * k + 2 == pre) {
				if (node[2 * k + 1] < x) {
					k = 2 * k + 1; break;
				}
			}
		}
		if (k == 0)return -1;
		while (k < sz - 1) {
			if (node[2 * k + 2] < x)k = 2 * k + 2;
			else k = 2 * k + 1;
		}
		return k - (sz - 1);
	}
	int searchright(int k, int x) {
		k += sz - 1;
		while (k > 0) {
			int pre = k;
			k = (k - 1) / 2;
			if (2 * k + 1 == pre) {
				if (node[2 * k + 2] < x) {
					k = 2 * k + 2; break;
				}
			}
		}
		if (k == 0)return mod;
		while (k < sz - 1) {
			if (node[2 * k + 1] < x)k = 2 * k + 1;
			else k = 2 * k + 2;
		}
		return k - (sz - 1);
	}
};
struct LazySegT {
private:
	int n; vector<int> node, lazy;
	const int init_c = mod;
public:
	LazySegT(vector<int> ori) {
		int sz = ori.size();
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
		rep(i, sz) {
			node[i + n - 1] = ori[i];
		}
		per(i, n - 1)node[i] = f(node[2 * i + 1], node[2 * i + 2]);
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
	void add(int x, int a, int b, int k = 0, int l = 0, int r = -1) {
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
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void update(int loc, ll x) {
		int k = 0, l = 0, r = n;
		stack<P> st;
		while (k < n - 1) {
			eval(k, l, r);
			st.push({ l,r });
			if (loc < (l + r) / 2) {
				k = 2 * k + 1;
				r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2;
				l = (l + r) / 2;
			}
		}
		eval(k, l, r);
		st.push({ l,r });
		node[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			st.pop();
			l = st.top().first, r = st.top().second;
			eval(2 * k + 1, l, (l + r) / 2);
			eval(2 * k + 2, (l + r) / 2, r);
			node[k] = f(node[2 * k + 1], node[2 * k + 2]);
		}
	}
};


void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	SegT st(a);
	vector<int> orilest(n), oririst(n);
	rep(i, n) {
		orilest[i] = a[i] - 2 * i;
		oririst[i] = a[i] + 2 * i;
	}
	LazySegT lest(orilest), rist(oririst),mst(a);
	auto isright = [&](int s, int g, int x)->bool {
		if (s <= g) {
			int mi = st.query(s, g + 1);
			mi = min(mi, x);
			return mi == a[g];
		}
		else {
			int mi = st.query(g, s + 1);
			mi = min(mi, x);
			return mi == a[g];
		}
	};
	
	int q; cin >> q;
	rep(i, q) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		x1--; x2--;
		int ans = mod;

		int ccl = st.searchleft(x1, y1);
		int ccr = st.searchright(x1, y1);
		if (ccr > n)ccr = n;
		

		int cl = st.searchleft(x2, y2);
		int cr = st.searchright(x2, y2);
		//cout << "? " << cl << " " << cr << "\n";

		if (y1 >= y2&&x1>=cl&&x1<=cr) {
			if (cl < ccl) {
				mst.add(-1, cl + 1, ccl + 1);
				lest.add(-1, cl + 1, ccl + 1);
				rist.add(-1, cl + 1, ccl + 1);
			}
			if (ccr < cr) {
				mst.add(-1, ccr, cr);
				lest.add(-1, ccr, cr);
				rist.add(-1, ccr, cr);
			}
		}
		
		cr = min(cr, n);
		int val;
		if (x1 <= x2) {
			
			//direct
			int mi = st.query(x1, x2 + 1);
			mi = min(mi, y1);
			val = x2 - x1 + min(abs(y2 - mi),1+y2);
			ans = min(ans, val);

			//cl
			if (cl >= 0) {
				val = abs(x1 - cl) + 1 + abs(x2 - cl) + abs(y2 - a[cl]);
				if (isright(x1, cl, y1))val--;
				ans = min(ans, val);
			}
			//[cl+1,x1]
			if (cl + 1 <= x1) {
				val = lest.query(cl + 1, x1 + 1);
				val += x2 + x1 + 1 - y2;
				ans = min(ans, val);
			}
			//[x1,x2]
			val = mst.query(max(cl+1,x1), x2 + 1);
			val += x2 - x1 + 1 - y2;
			ans = min(ans, val);
			//[x2,cr)
			val = rist.query(x2, cr);
			val += -x2 - x1 - y2 + 1;
			ans = min(ans, val);
			//cr
			if (cr < n) {
				val = abs(x1 - cr) + 1 + abs(x2 - cr) + abs(y2 - a[cr]);
				if (isright(x1, cr, y1))val--;
				ans = min(ans, val);
			}
		}
		else {
			//direct
			int mi = st.query(x2, x1 + 1);
			mi = min(mi, y1);
			val = x1 - x2 + min(abs(y2 - mi),1+y2);
			ans = min(ans, val);

			//cl
			if (cl >= 0) {
				val = abs(x1 - cl) + 1 + abs(x2 - cl) + abs(y2 - a[cl]);
				if (isright(x1, cl, y1))val--;
				ans = min(ans, val);
			}
			//[cl+1,x2]
			if (cl + 1 <= x2) {
				val = lest.query(cl + 1, x2 + 1);
				val += x2 + x1 + 1 - y2;
				ans = min(ans, val);
			}
			//[x2,x1]
			val = mst.query(x2, min(cr,x1 + 1));
			val += x1 - x2 + 1 - y2;
			ans = min(ans, val);
			//[x1,cr)
			if (x1 <= cr) {
				val = rist.query(x1, cr);
				val += -x2 - x1 - y2 + 1;
				ans = min(ans, val);
			}
			//cr
			if (cr < n) {
				val = abs(x1 - cr) + 1 + abs(x2 - cr) + abs(y2 - a[cr]);
				if (isright(x1, cr, y1))val--;
				ans = min(ans, val);
			}
		}
		cout << ans << "\n";

		if (y1 >= y2&&x1>=cl&&x1<=cr) {
			if (cl < ccl) {
				mst.add(1, cl + 1, ccl + 1);
				lest.add(1, cl + 1, ccl + 1);
				rist.add(1, cl + 1, ccl + 1);
			}
			if (ccr < cr) {
				mst.add(1, ccr, cr);
				lest.add(1, ccr, cr);
				rist.add(1, ccr, cr);
			}
		}
	}
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