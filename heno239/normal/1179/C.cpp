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
const ll mod = 1000000007;
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
int mn = (1 << 20);

struct SegT {
private:
	int n; vector<int> node, lazy;
	const int init_c = mod;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, 0);
		lazy.resize(2 * n - 1, 0);
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
	void add(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x; eval(k, l, r);
		}
		else {
			add(a, b, x, k * 2 + 1, l, (l + r) / 2);
			add(a, b, x, k * 2 + 2, (l + r) / 2, r);
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
	int search_id() {
		int z = query(0, n);
		if (z >= 0)return -1;
		int k = 0, l = 0, r = n;
		while (k < n - 1) {
			int mid = (l + r) / 2;
			eval(2 * k + 1,l,mid); eval(2 * k + 2,mid,r);
			if (node[2 * k + 2]<0) {
				k = 2 * k + 2, l = mid;
			}
			else {
				k = 2 * k + 1, r = mid;
			}
		}
		return k - (n - 1);
	}

};

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	SegT st(1 << 20);
	rep(i, n) {
		cin >> a[i];
		st.add(0, a[i]+1 , -1);
	}
	rep(i, m) {
		cin >> b[i];
		st.add(0, b[i] + 1, 1);
	}
	int q; cin >> q;
	rep(aa, q) {
		int t; cin >> t;
		int i, val; cin >> i >> val; i--;
		if (t == 1) {
			int pre = a[i];
			st.add(0, pre + 1, 1);
			st.add(0, val + 1, -1);
			a[i] = val;
		}
		else {
			int pre = b[i];
			st.add(0, pre + 1, -1);
			st.add(0, val + 1, 1);
			b[i] = val;
		}
		cout << st.search_id() << endl;
	}
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