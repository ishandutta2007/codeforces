#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 222222;
const int L = 20;
vector<int> a[N];

int tin[N], tout[N];
int timer;
int par[L][N];
int level[N];

void dfs(int v, int p = -1) {
	tin[v] = timer++;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		par[0][x] = v;
		level[x] = level[v] + 1;
		dfs(x, v);
	}
	tout[v] = timer;
}

bool isPar(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (isPar(v, u)) {
		return v;
	}
	for (int i = L - 1; i >= 0; --i) {
		if (!isPar(par[i][v], u)) {
			v = par[i][v];
		}
	}
	return par[0][v];
}

struct Vertex {
	int v;
	int vid;
	int spd;
	int ansid;

	Vertex(): v(0), vid(-1), spd(0), ansid(-1) {};
	Vertex(int _v): v(_v), vid(-1), spd(0), ansid(-1) {};
	Vertex(int _v, int _vid, int _spd, int _ansid): v(_v), vid(_vid), spd(_spd), ansid(_ansid) {}

	bool operator <(const Vertex& ot) const {
		return tin[v] < tin[ot.v];
	}
};

struct Fraction {
	long long x, y;

	bool operator <(const Fraction& ot) const {
		// return x * ot.y < y * ot.x;
		return (x + y - 1) / y < (ot.x + ot.y - 1) / ot.y;
	}
};

void solve() {
	int k = nxt(), m = nxt();
	vector<int> ans(m);
	map<int, Vertex, function<bool(int, int)>> M([&](int u, int v) { return tin[u] < tin[v]; });
	for (int i = 0; i < k; ++i) {
		int v = nxt() - 1, spd = nxt();
		M[v] = {v, i, spd, -1};
	}
	for (int i = 0; i < m; ++i) {
		int v = nxt() - 1;
		M[v].v = v;
		M[v].ansid = i;
	}
	vector<int> lcas;
	for (auto it = M.begin(); it != M.end(); ++it) {
		if (next(it) == M.end()) {
			break;
		}
		lcas.push_back(lca(it->first, next(it)->first));
	}
	for (int l : lcas) {
		M[l].v = l;
	}

	vector<Vertex> verts;
	for (const auto& it : M) {
		verts.push_back(it.second);
	}

	vector<vector<pair<int, int>>> g(verts.size());
	{
		vector<int> st;
		for (int i = 0; i < (int)verts.size(); ++i) {
			const auto& ver = verts[i];
			while (!st.empty() && !isPar(verts[st.back()].v, ver.v)) {
				st.pop_back();
			}
			if (!st.empty()) {
				g[st.back()].push_back({i, level[ver.v] - level[verts[st.back()].v]});
				g[i].push_back({st.back(), level[ver.v] - level[verts[st.back()].v]});
			}
			st.push_back(i);
		}
	}

	vector<int> virus_id(verts.size(), -1);
	vector<Fraction> infection_time(verts.size(), {(int)1e9, 1});
	set<tuple<Fraction, int, int>> S;
	for (int i = 0; i < (int)verts.size(); ++i) {
		if (verts[i].vid > -1) {
			virus_id[i] = verts[i].vid;
			infection_time[i] = {0, verts[i].spd};
			S.insert({infection_time[i], virus_id[i], i});
		}
	}
	while (!S.empty()) {
		auto [t, vid, v] = *S.begin();
		S.erase(S.begin());
		if (verts[v].ansid > -1) {
			ans[verts[v].ansid] = vid;
		}
		// cerr << "vertex " << verts[v].v + 1 << " is infected by " << virus_id[v] + 1 << " at turn number " << (infection_time[v].x + infection_time[v].y - 1) / infection_time[v].y << "\n";
		for (const auto& [x, d] : g[v]) {
			Fraction cand = t;
			cand.x += d;
			if (tie(cand, vid) < tie(infection_time[x], virus_id[x])) {
				S.erase({infection_time[x], virus_id[x], x});
				infection_time[x] = cand;
				virus_id[x] = vid;
				S.insert({infection_time[x], virus_id[x], x});
			}
		}
	}
	for (int x : ans) {
		printf("%d ", x + 1);
	}
	printf("\n");
}

int main() {
	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	dfs(0);
	for (int i = 1; i < L; ++i) {
		for (int j = 0; j < n; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}

	int q = nxt();
	while (q--) {
		solve();
	}

	return 0;
}