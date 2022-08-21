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
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct SegT {
private:
	int n; vector<ll> node, lazy;
	const ll init_c = INF;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
	}
	SegT(vector<ll> v) {
		int sz = v.size();
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
		rep(i, sz) {
			node[i + n - 1] = v[i];
		}
		per(i, n - 1)node[i] = f(node[2 * i + 1], node[2 * i + 2]);
	}
	ll f(ll a, ll b) {
		return max(a, b);
	}
	void eval(int k, int l, int r) {
		if (node[k] < lazy[k]) {
			node[k] = lazy[k];
		}
		if (r - l > 1) {
			lazy[2 * k + 1] = max(lazy[2*k+1],lazy[k]);
			lazy[2 * k + 2] = max(lazy[2*k+2],lazy[k]);
		}
		lazy[k] = 0;
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] = max(lazy[k],x); eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	void update(ll x, int loc, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= loc || loc + 1 <= l)return;
		if (loc <= l && r <= loc + 1) {
			node[k] = x;
		}
		else {
			update(x, loc, k * 2 + 1, l, (l + r) / 2);
			update(x, loc, k * 2 + 2, (l + r) / 2, r);
		}
	}
	void complete(int k = 0, int l = 0,int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (k < n - 1) {
			complete(2 * k + 1, l,(l + r) / 2);
			complete(2 * k + 2, (l + r) / 2, r);
		}

	}
	vector<ll> ans(int sz) {
		vector<ll> ret(sz);
		rep(i, sz) {
			ret[i] = node[i + n - 1];
		}
		return ret;
	}
};

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	SegT st(a);
	int q; cin >> q;
	rep(aa, q) {
		/*cout << "!!" << endl;
		st.complete();
		vector<ll> ans = st.ans(n);
		rep(i, n) {
			if (i > 0)cout << " ";
			cout << ans[i];
		}
		cout << endl;*/
		int t; cin >> t;
		if (t == 1) {
			int p; ll x; cin >> p >> x; p--;
			st.update(x,p);
		}
		else {
			ll x; cin >> x;
			st.add(x, 0, n);
		}
	}
	st.complete();
	vector<ll> ans = st.ans(n);
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}