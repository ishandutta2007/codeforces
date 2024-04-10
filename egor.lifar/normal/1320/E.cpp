#include <bits/stdc++.h>


using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 400228;


int n;
vector<int> g[MAXN];
int vs[MAXN], s[MAXN];
vector<int> st;
int z[MAXN];
int in[MAXN], out[MAXN];
int timer = 0;
int deep[MAXN];
int jump[22][MAXN];



void dfs(int u, int pr = -1) {
	timer++;
	in[u] = timer;
	for (auto h: g[u]) {
		if (h != pr) {
			deep[h] = deep[u] + 1;
			jump[0][h] = u;
			dfs(h, u);
		}
	}
	out[u] = timer;
}


bool isp(int a, int b) {
	return in[a] <= in[b] && out[b] <= out[a];
}


int lca(int a, int b) {
	if (isp(a, b)) {
		return a;
	}
	if (isp(b, a)) {
		return b;
	}
	for (int k = 18; k >= 0; k--) {
		if (!isp(jump[k][a], b)) {
			a = jump[k][a];
		}
	}
	return jump[0][a];
}

int dist(int a, int b) {
	return deep[a] + deep[b] - 2 * deep[lca(a, b)];
}


bool comp(int a, int b) {
	return in[a] < in[b];
}


vector<int> v[MAXN];
int pre[MAXN];
vector<pair<int, int> > sf[MAXN];
int col[MAXN];
int curd[MAXN];

 
void solve() {
	int k, m;
	cin >> k >> m;
	st.clear();
	for (int i = 1; i <= k; i++) {
		cin >>  vs[i] >> s[i];
		vs[i]--;
		st.pb(vs[i]);
	}
	for (int i = 0; i < m; i++) {
		int u;
		cin >> u;
		u--;
		z[i] = u;
		st.pb(z[i]);
	}
	sort(all(st), comp);
	st.resize(distance(st.begin(), unique(all(st))));
	vector<int> sts;
	vector<int> ts;
	for (int i = 0; i < sz(st); i++) {
		int j = st[i];
		ts.pb(j);
		bool was = false;
		int last = -1;
		while (!sts.empty()) {
			int f = sts.back();
			if (isp(f, j)) {
				int a = (last == -1 ? f: lca(last, j));
				was = true;
				if (a != f) {
					v[f].pop_back();
					v[f].pb(a);
					ts.pb(a);
					v[a].pb(last);
					v[a].pb(j);
					sts.pb(a);
					sts.pb(j);
				} else {
					v[f].pb(j);
					sts.pb(j);
				}
				break;
			}
			sts.pop_back();	
			last = f;
		}
		if (!was) {
			if (last != -1) {
				was = true;
				int a = lca(last, j);
				ts.pb(a);
				v[a].pb(last);
				v[a].pb(j);
				sts.pb(a);
				sts.pb(j);
			} else {
				sts.pb(j);
			}
		}
	}
	sort(all(ts));
	ts.resize(distance(ts.begin(), unique(all(ts))));
	for (auto x: ts) {
		sf[x].clear();
		col[x] = 0;
		curd[x] = 0;
	}
	for (int i = 1; i <= k; i++) {
		col[vs[i]] = i;
		curd[vs[i]] = 0;
	}
	for (auto x: ts) {
		for (auto y: v[x]) {
			int len = dist(x, y);
			sf[x].pb({y, len});
			sf[y].pb({x, len});
		}
		v[x].clear();
	}
	set<pair<pair<int, int>, pair<int, pair<int, int> > > > kek;
	for (int i = 1; i <= k; i++) {
		for (auto x: sf[vs[i]]) {
			if (col[x.first]) {
				continue;
			}
			kek.insert({{(x.second + s[i] - 1) / s[i], i}, {vs[i], {x.first, x.second}}});
		}
	}
	while (!kek.empty()) {
		auto a = *kek.begin();
		kek.erase(a);
		if (col[a.second.second.first]) {
			continue;
		}
		col[a.second.second.first] = a.first.second;
		curd[a.second.second.first] = curd[a.second.first] + a.second.second.second;
		for (auto x: sf[a.second.second.first]) {
			if (!col[x.first]) {
				int f =curd[a.second.second.first] + x.second;
				kek.insert({{(f + s[a.first.second] - 1) / s[a.first.second], a.first.second}, {a.second.second.first, x}}); 
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cout << col[z[i]] << ' ';
	}
	cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0);
	for (int i = 1; i <= 18; i++) {
		for (int j = 0; j < n; j++) {
			jump[i][j] = jump[i - 1][jump[i -1][j]];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		solve();
	}
}