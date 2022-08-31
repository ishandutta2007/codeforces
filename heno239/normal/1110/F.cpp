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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

struct SegT {
private:
	int n; vector<ll> node, lazy;
	const ll init_c = INF;
public:
	void init(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
	}
	ll f(ll a, ll b) {
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
	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void update(int k, ll x) {
		k += n - 1;
		node[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[2 * k + 1], node[2 * k + 2]);
		}
	}
};
SegT sg;
int n, q;
struct edge {
	int to; ll cost;
};
vector<edge> G[1 << 19];
int l[1 << 19], r[1 << 19];
void dfs(int id,ll s) {
	l[id] = r[id] = id;
	rep(j, G[id].size()) {
		int to = G[id][j].to;
		ll c = G[id][j].cost;
		dfs(to,s+c);
		l[id] = min(l[id], l[to]);
		r[id] = max(r[id], r[to]);
	}
	if (G[id].size() == 0) {
		sg.update(id, s);
	}
}
struct query {
	int le, ri,id;
};
queue<query> que[1 << 19];
ll ans[1 << 19];
void solve(int id) {
	while (!que[id].empty()) {
		query z = que[id].front(); que[id].pop();
		ans[z.id] = sg.query(z.le, z.ri + 1);
	}
	rep(j, G[id].size()) {
		int to = G[id][j].to;
		ll c = G[id][j].cost;
		sg.add(c, 0, n);
		sg.add(-2 * c, l[to], r[to] + 1);
		solve(to);
		sg.add(-c, 0, n);
		sg.add(2 * c, l[to], r[to] + 1);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> q; sg.init(n);
	rep1(i, n - 1) {
		int p; ll w; cin >> p >> w; p--;
		G[p].push_back({ i,w });
	}
	dfs(0,0);
	rep(i, q) {
		int v, le, ri; cin >> v >> le >> ri; v--; le--; ri--;
		que[v].push({ le,ri,i });
	}
	solve(0);
	rep(i, q) {
		cout << ans[i] << endl;
	}
	//stop
	return 0;
}