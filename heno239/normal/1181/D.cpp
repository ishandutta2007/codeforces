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

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = -mod;
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, 0);
	}
	int f(int a, int b) {
		return a + b;
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
	//x
	int sloc(int x) {
		x++;
		int k = 0;
		int cur = 0;
		while (k < sz-1) {
			int l = 2 * k + 1, r = 2 * k + 2;
			if (cur + node[l] >= x) {
				k = l;
			}
			else {
				k = r; cur += node[l];
			}
		}
		return k - (sz - 1);
	}
};
void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<ll> ans(q);
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i]; a[i]--;
	}
	vector<LP> v(q);
	rep(i, q) {
		ll t; cin >> t;
		v[i] = { t-n-1,i };
	}
	sort(v.begin(), v.end());
	vector<P> c(m);
	rep(i, m)c[i].first = 0, c[i].second = i;
	rep(i, n) {
		c[a[i]].first++;
	}
	sort(c.begin(), c.end());
	SegT st(m);
	int sz = 0;
	int le = 0;
	ll cur = 0;
	rep(i, m) {
		sz++;
		st.update(c[i].second, 1);
		while (i + 1 < m&&c[i].first == c[i + 1].first) {
			i++;
			sz++;
			st.update(c[i].second, 1);
		}
		if (i == m - 1)break;
		ll dif = c[i + 1].first - c[i].first;
		while (le < q&&v[le].first < cur + dif * sz) {
			ll d = v[le].first - cur;
			ll r = d % sz;
			//cout << r << " " << sz << endl;
			ans[v[le].second] = st.sloc(r);
			le++;
		}
		cur += dif * sz;
	}
	while (le < q) {
		ll d = v[le].first - cur;
		ll r = d % sz;
		ans[v[le].second] = r;
		le++;
	}
	rep(i, q)cout << ans[i] + 1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	//init();
	solve();
	//stop
	return 0;
}