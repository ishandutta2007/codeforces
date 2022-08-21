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
	int n; vector<int> node, lazy;
	const int init_c = -mod;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, 0);
		lazy.resize(2 * n - 1, 0);
	}
	int f(int a, int b) {
		return max(a, b);
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
};

void solve() {
	int n, r; cin >> n >> r;
	vector<P> a(n);
	rep(i, n) {
		cin >> a[i].first >> a[i].second;
		int le = a[i].first - a[i].second;
		int ri = a[i].first + a[i].second;
		a[i] = { le,ri };
	}
	vector<int> vy;
	rep(i, n) {
		vy.push_back(a[i].second);
	}
	sort(vy.begin(), vy.end());
	vy.erase(unique(vy.begin(), vy.end()), vy.end());
	vector<int> le, ri;
	{
		map<int, int> mp;
		rep(i, vy.size()) {
			mp[vy[i]] = i;
		}
		rep(i, n) {
			a[i].second = mp[a[i].second];
		}
		le.resize(vy.size()); ri.resize(vy.size());
		int lid = 0, rid = 0;
		rep(i, vy.size()) {
			while (vy[i] - vy[lid] > 2 * r)lid++;
			le[i] = lid;
			while (rid + 1 < vy.size() && vy[rid + 1] - vy[i] <= 2 * r)rid++;
		
			ri[i] = rid;
		}
	}
	SegT st(vy.size());
	sort(a.begin(), a.end());
	int rid = 0;
	int ans = 0;
	rep(i, n) {
		while (rid < n&&a[rid].first - a[i].first <= 2 * r) {
			int z = a[rid].second;
			st.add(1, z, ri[z]+1);
			rid++;
		}
		int val = st.query(0, vy.size());
		ans = max(ans, val);
		int z = a[i].second;
		st.add(-1, z, ri[z]+1);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
	//stop
	return 0;
}