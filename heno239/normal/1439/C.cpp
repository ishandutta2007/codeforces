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

struct ste {
	ll ma, sum; int cnt;
};
struct SegT {
private:
	int n; vector<ste>node;vector<ll> lazy;
public:
	SegT(vector<int> ori) {
		int sz = ori.size();
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, {0,0,0});
		lazy.resize(2 * n - 1, -1);
		rep(i, sz) {
			node[i + n - 1] = { ori[i],ori[i],1 };
		}
		per(i, n - 1)node[i] = f(node[2 * i + 1], node[2 * i + 2]);
	}
	ste f(ste a, ste b) {
		return { max(a.ma,b.ma),a.sum + b.sum,a.cnt + b.cnt };
	}
	void eval(int k) {
		if (lazy[k] < 0)return;
		node[k] = { lazy[k],lazy[k] * node[k].cnt,node[k].cnt };
		if (k<n-1) {
			lazy[2 * k + 1] = lazy[k];
			lazy[2 * k + 2] = lazy[k];
		}
		lazy[k] = -1;
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] = x; eval(k);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	//maximum index with >=x
	int searchleft(int x) {
		int k = 0;
		eval(k);
		if (node[k].ma < x)return -1;
		while (k < n - 1) {
			eval(2 * k + 2); eval(2 * k + 1);
			if (node[2 * k + 2].ma >= x)k = 2 * k + 2;
			else k = 2 * k + 1;
		}
		return k - (n - 1);
	}
	P searchright(int s,int val) {
		int k = 0, l = 0, r = n;
		while (k < n - 1) {
			eval(k);
			int m = (l + r) / 2;
			if (s < m) {
				r = m;
				k = 2 * k + 1;
			}
			else {
				l = m; k = 2 * k + 2;
			}
		}
		eval(k);
		int rest = val - node[k].sum;
		while (k > 0) {
			int pre = k;
			k = (k - 1) / 2;
			if (2 * k + 2 == pre)continue;
			else {
				eval(2 * k + 2);
				if (node[2 * k + 2].sum > rest) {
					k = 2 * k + 2; break;
				}
				else {
					rest -= node[2 * k + 2].sum;
				}
			}
		}
		if (k == 0)return { -1,0 };
		while (k < n - 1) {
			eval(2 * k + 1); eval(2 * k + 2);
			if (node[2 * k + 1].sum > rest) {
				k = 2 * k + 1;
			}
			else {
				rest -= node[2 * k + 1].sum;
				k = 2 * k + 2;
			}
		}
		return { k - (n - 1),rest };
	}
	
	int query(int s, int val,int sz) {
		int res = 0;
		while (s < sz&&val>0) {
			int nex = searchleft(val + 1);
			nex++;
			s = max(s, nex);
			if (s >= sz)break;
			P p = searchright(s, val);
			int r = p.first; val = p.second;
			if (r < 0)r = sz; r = min(r, sz);
			res += r - s;
			//cout << "? " << s << " " << r << "\n";
			s = r;
		}
		return res;
	}
};

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n); rep(i, n)cin >> a[i];
	SegT st(a);
	rep(i, q) {
		int t; cin >> t;
		if (t == 1) {
			int x, y; cin >> x >> y; x--;
			int le = st.searchleft(y);
			st.add(y, le + 1, x + 1);
		}
		else {
			int x, y; cin >> x >> y; x--;
			int ans = st.query(x, y, n);
			cout << ans << "\n";
		}
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(15);
     //init_f();
     //init();
     //expr();
     //int t; cin >> t; rep(i, t)
    solve();
    return 0;
}