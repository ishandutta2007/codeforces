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

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = mod;
public:
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
};
void solve() {
	int n; cin >> n;
	vector<int>a(n);
	rep(i, n)cin >> a[i];


	vector<int> x;
	rep(i, n) {
		x.push_back(a[i]);
	}
	sort(all(x));
	x.erase(unique(all(x)), x.end());
	rep(i, n) {
		a[i] = lower_bound(all(x), a[i]) - x.begin();
	}
	vector<vector<int>> locs(x.size());
	rep(i, n) {
		locs[a[i]].push_back(i);
	}
	vector<int> ri(n, mod);
	vector<int> pre(n, -1);
	rep(i, x.size()) {
		rep(j, (int)locs[i].size() - 1) {
			ri[locs[i][j]] = locs[i][j + 1];
			pre[locs[i][j + 1]] = locs[i][j];
		}
	}



	vector<int> r(n,mod);
	SegT st(n);

	rep(i, n) {
		if (pre[i] < 0) {
			st.update(i, ri[i]);
			continue;
		}


		r[pre[i]] = st.query(pre[i] + 1, i);

		st.update(pre[i], mod);
		st.update(i, ri[i]);
	}

	rep(i, x.size()) {
		rep(j, (int)locs[i].size() - 3) {
			int f = locs[i][j];
			int t = locs[i][j + 3];
			r[f] = min(r[f], t);
		}
	}

	vector<int> tos(n+1);
	vector<P> ps(n + 1);
	tos[n] = mod;
	ps[n] = { mod,0 };
	per(i, n) {
		if (r[i] < tos[i + 1]) {
			tos[i] = r[i];
			ps[i] = { i,r[i] };
		}
		else {
			tos[i] = tos[i + 1];
			ps[i] = ps[i + 1];
		}
	}
	vector<int> ans;
	int cur = 0;
	while (cur<n) {
		if (tos[cur] < mod) {
			int s1 = x[a[ps[cur].first]];
			int s2 = x[a[ps[cur].second]];
			rep(j, 2) {
				ans.push_back(s1); ans.push_back(s2);
			}
			cur = tos[cur] + 1;
		}
		else break;
	}
	cout << ans.size() << "\n";
	rep(i, ans.size()) {
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

	solve();
	stop
		return 0;
}