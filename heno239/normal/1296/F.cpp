#include<bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;

const ll mod = 998244353;
const ll INF = (1e+18) + 7;
typedef pair<int, int>P;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define all(v) (v).begin(),(v).end()

const int sup = 1000000;

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = 1;
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	int f(int a, int b) {
		return max(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = f(node[k],a);
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

struct edge {
	int to, id;
};
int n;
vector<edge> G[1<<17];
int par[1 << 17][17];
int depth[1 << 17];

void dfs(int id, int fr) {
	par[id][0] = fr;
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		depth[e.to] = depth[id] + 1;
		dfs(e.to, id);
	}
}
void lca_init() {
	dfs(0, -1);
	rep(j, 16) {
		rep(i, n) {
			if (par[i][j] < 0)par[i][j + 1] = -1;
			else par[i][j + 1] = par[par[i][j]][j];
		}
	}
}
int lca(int a, int b) {
	if (depth[a] > depth[b])swap(a, b);
	int dif = depth[b] - depth[a];
	rep(i, 17) {
		if ((dif >> i) & 1) {
			b = par[b][i];
		}
	}
	if (a == b)return a;
	per(i, 17) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i], b = par[b][i];
		}
	}
	return par[a][0];
}

int trans[1 << 17];
int ri[1 << 17];

void etdfs(int id, int fr,int &tmp) {
	trans[id] = tmp; tmp++;
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		etdfs(e.to, id, tmp);
	}
	ri[trans[id]] = tmp;
}
void euler_tour() {
	int tmp = 0;
	etdfs(0, -1, tmp);
}

int f[1 << 17];

vector<P> ad[1 << 17];
void add(int a, int b, int x) {
	int l = lca(a, b);
	ad[l].push_back({ a,x });
	ad[l].push_back({ b,x });
}

int cost[1 << 17][17];
void refl(int id, int fr, SegT &st) {
	for (P p : ad[id]) {
		int v = p.first;
		int val = p.second;
		st.update(trans[v], val);
	}
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		f[e.id] = st.query(trans[e.to], ri[trans[e.to]]);
		cost[e.to][0] = f[e.id];
		refl(e.to, id, st);
	}
}


void refl(SegT &st) {
	refl(0, -1, st);
	cost[0][0] = sup;
	rep(j, 16) {
		rep(i, n) {
			if (par[i][j] < 0)cost[i][j + 1] = sup;
			else cost[i][j + 1] = min(cost[i][j], cost[par[i][j]][j]);
		}
	}
}

int calc_cost(int a, int b) {
	int l = lca(a, b);
	int res = sup;
	int dif = depth[a] - depth[l];
	rep(i, 17) {
		if ((dif >> i)&1) {
			res = min(res, cost[a][i]);
			a = par[a][i];
		}
	}
	dif = depth[b] - depth[l];
	rep(i, 17) {
		if ((dif >> i) & 1) {
			res = min(res, cost[b][i]);
			b = par[b][i];
		}
	}
	return res;
}


void solve() {
	cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back({ b,i });
		G[b].push_back({ a,i });
	}
	lca_init(); euler_tour();
	int m; cin >> m;
	vector<int> l(m), r(m), val(m);
	rep(i, m) {
		cin >> l[i] >> r[i] >> val[i]; l[i]--; r[i]--;
		add(l[i], r[i], val[i]);
	}
	SegT st(n);
	refl(st);
	bool valid = true;
	rep(i, m) {
		int c = calc_cost(l[i], r[i]);
		if (c != val[i])valid = false;
	}
	if (!valid) {
		cout << -1 << endl;
	}
	else {
		rep(i, n - 1) {
			if (i > 0)cout << " ";
			cout << f[i];
		}
		cout << endl;
	}
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}