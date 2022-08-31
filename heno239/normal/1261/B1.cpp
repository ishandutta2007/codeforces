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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = 0;
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	int f(int a, int b) {
		return a+b;
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
	int find(int x) {
		int k = 0;
		while (k < sz - 1) {
			int vl = node[2 * k + 1];
			if (x <= vl) {
				k = 2 * k + 1;
			}
			else {
				k = 2 * k + 2;
				x -= vl;
			}
		}
		return k - (sz - 1);
	}
};

bool comp(P a, P b) {
	if (a.first != b.first)return a.first > b.first;
	return a.second < b.second;
}
vector<P> querys[1 << 18];
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	vector<P> v;
	rep(i, n) {
		cin >> a[i];
		v.push_back({ a[i],i });
	}
	sort(v.begin(), v.end(), comp);
	int q; cin >> q;
	rep(i, q) {
		int k, p; cin >> k >> p;
		querys[k].push_back({ p,i });
	}
	vector<int> ans(q);
	SegT st(n);
	rep1(i, n) {
		st.update(v[i - 1].second, 1);
		rep(j, querys[i].size()) {
			int id = querys[i][j].second;
			int p = querys[i][j].first;
			ans[id] = st.find(p);
		}
	}
	rep(i, q)cout << a[ans[i]] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}