
/*
 



















 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
const string FILENAME = "input";
const int MAXN = 400228;



int n, q;        
vector<int> g[MAXN];
int mx[MAXN];
int deep[MAXN];
int p[MAXN];
int jump[MAXN][20];
vector<int> v[MAXN];
int in[MAXN];
int out[MAXN];
int timer = 0;
int sz[MAXN];


struct tree
{
	vector<long long>  mod;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		mod.resize(2 * ss, 0);
	}
	void add(int v, int vl, int vr, int l, int r, int x) {
		if (vl > r || vr < l) {
			return;
		}
		if (l <= vl && vr <= r) {
			mod[v] += x;
			return;
		}
		add(v * 2, vl, (vl + vr) / 2, l, r, x);
		add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
	}
	int getsum(int v) {
		v += ss - 1;
		long long ans = 0;
		while (v > 0) {
			ans += mod[v];
			v >>= 1;
		}
		return ans;
	}
	void inc(int l, int r, int x) {
		add(1, 1, ss, l, r, x);
	}
};


tree tr;


void dfs(int u, int pr = -1) {
	timer++;
	in[u] = timer;
	mx[u] = p[u];
	sz[u] = 1;
	for (auto h: g[u]) {
		if (h == pr) {
			continue;
		}
		v[u].pb(h);
		deep[h] = deep[u] + 1;
		jump[h][0] = u;
		dfs(h, u);
		sz[u] += sz[h];
		chkmax(mx[u], mx[h]);
	}	
	int t = 0;
	for (auto x: v[u]) {
		chkmax(t, sz[x]);
	}
	for (auto &x: v[u]) {
		if (sz[x] == t) {
			swap(x, v[u][0]);
			break;
		}
	}
	out[u] = timer;
}


bool isparent(int a, int b) {
	return in[a] <= in[b] && out[b] <= out[a];
}


int lca(int a, int b) {
	if (isparent(a, b)) {
		return a;
	}
	if (isparent(b, a)) {
		return b;
	}
	for (int k = 19; k >= 0; k--) {
		if (!isparent(jump[a][k], b)) {
			a = jump[a][k];
		}
	}
	return jump[a][0];
}



int who[MAXN];
int root;




struct seq
{
	int value;
	int stv;
	int l, r;
	seq(){}
	seq(int _value, int _stv, int _l, int _r) {
		value = _value;
		stv = _stv;
		l = _l;
		r = _r;
	}
};


bool operator <(seq a, seq b) {
	return a.l < b.l;
}

int where[MAXN];
set<seq> f[MAXN];
int deepest[MAXN];

void dfs1(int u, int up) {
	where[u] = up;
	chkmax(deepest[up], deep[u]);
	f[up].insert(seq(mx[u], u, deep[u], deep[u]));
	if (v[u].empty()) {
		return;
	}
	dfs1(v[u][0], up);
	for (int i = 1; i < sz(v[u]); i++) {
		dfs1(v[u][i], v[u][i]);
	}
}


int getmaxv(int u) {
	int id = where[u];
		//cout << u << ' ' << id << endl;
	auto it = f[id].upper_bound(seq(0, 0, deep[u], 0));
	//cout << (*it).l << endl;
	it--;
	//cout << (*it).l << ' ' << (*it).r << ' ' << deep[u] << endl;
	return (*it).value;
}

int getlen(int a, int b) {
	return deep[a] + 1 + deep[b] + 1 - 2 * deep[lca(a, b)] - 1;
}

int getcntpath(int a) {
	int k = getmaxv(a);
	int u = who[k];
	//cout << getlen(u, a) << endl;
	return getlen(u, a);
}

int when(int a) {
	int f = tr.getsum(getmaxv(a));
	//cout << f  << endl;
	return f + getcntpath(a);
}


void del(seq a) {
	tr.inc(a.value + 1, n + q + 1, -(a.r - a.l + 1));
}


void add(seq a) {
	tr.inc(a.value + 1, n + q + 1, (a.r - a.l + 1));
}



void proceed(int id, int l, int r, int val) {
	chkmax(l, deep[id]);
	chkmin(r, deepest[id]);
	if (l > r)  {
		return;
	}
	auto it =  f[id].upper_bound(seq(0, 0, l, 0));
	if (it != f[id].begin()) {
		it--;
	}
	vector<seq> dels;
	while (it != f[id].end()) {
		if ((*it).l > r) {
			break;
		}
		if ((*it).r >= l) {
			dels.pb(*it);
		}
		it++;
	}
	vector<seq> adds;
	adds.pb(seq(val, 0, l, r));
	for (auto x: dels) {
		del(x);
		f[id].erase(x);
		if (l <= x.l && x.r <= r) {
			continue;
		}
		if (x.l < l) {
			adds.pb(seq(x.value, 0, x.l, l - 1));
		} 
		if (x.r > r) {
			adds.pb(seq(x.value, 0, r + 1, x.r));
		}
	}
	for (auto x: adds) {
		add(x);
		f[id].insert(x);
	}
}

void setvert(int a, int b, int value) {
	int cur = a;
	while (true) {
		proceed(where[cur], deep[b], deep[cur], value);
		if (where[cur] == n) {
			break;
		}
		cur = jump[where[cur]][0];
		if (deep[cur] < deep[b]) {
			break;
		}
	}
}

void setpath(int a, int b, int value) {
	if (!isparent(a, b)) {
		swap(a, b);
	}
	if (isparent(a, b)) {
		setvert(b, a, value);
	} else {
		int c = lca(a, b);
	//	cout << a << ' ' << b << ' ' << c << endl;
		setvert(b, c, value);
		setvert(a, c, value);
	}
}

int  main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);	
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		who[i] = i;
	}
	dfs(n);
	dfs1(n, n);
	jump[n][0] = n;
	for (int k = 1; k <= 19; k++) {
		for (int i = 1; i <= n; i++) {
			jump[i][k] = jump[jump[i][k - 1]][k - 1];
		}
	}
	int cur = n + 1;
	tr.init(n + q + 2);
	for (int i = 1; i <= n; i++) {
		tr.inc(mx[i] + 1, n + q + 1, 1);
	//	cout << mx[i] << ' ';
	}
	//cout << endl;
	root = n;
	for (int i = 0; i < q; i++) {
		string t;
		cin >> t;
		if (t== "when") {
			int x;
			cin >> x;
			//cout << getmaxv(x) << '\n';
			cout << when(x) << '\n';
		} else if (t == "compare") {
			int x, y;
			cin >> x >> y;
			if (when(x) < when(y)) {
				cout << x << '\n';
			} else {
				cout << y << '\n';
			}
		} else if (t == "up") {
			int x;
			cin >> x;
			if (root == x) {
				continue;
			}
			p[x] = cur;
			who[cur] = x;
			cur++;
		//	cout << p[root] << endl;
			setpath(root, x, p[root]);
			setpath(x, x, p[x]);
			root = x;
		}
	}
 	return 0; 
}