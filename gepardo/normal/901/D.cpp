#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>

using namespace std;

struct Edge {
	int src, dst, idx;
};

int main() {
	ios_base::sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	vector<int64_t> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	vector<Edge> edges(m);
	vector< vector<Edge> > g(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		edges[i] = {a, b, i};
		g[a].push_back({a, b, i});
		g[b].push_back({b, a, i});
	}
	vector<int64_t> ans(m, 0);
	
	auto edgify = [&](int eid, int64_t val) {
		ans[eid] += val;
		w[edges[eid].src] -= val;
		w[edges[eid].dst] -= val;
	};
	
	for (int i = 0; i < m; i++) {
		edgify(i, 1);
	}
	
	vector<int> color(n, -1);
	vector< pair<int, int> > loop;
	vector< pair<int, int> > stk;
	
	function<bool(int, int)> dfs = [&](int v, int c) {
		if (color[v] >= 0) {
			if (color[v] == c) {
				return true;
			} else {
				int i = (int)stk.size() - 1;
				do {
					loop.push_back(stk[i]);
					i--;
				} while (i >= 0 && stk[i].first != v);
				return false;
			}
		}
		color[v] = c;
		for (Edge edg: g[v]) {
			stk.emplace_back(edg.dst, edg.idx);
			assert((int)stk.size() <= n+1);
			bool dfsRes = dfs(edg.dst, c ^ 1);
			stk.pop_back();
			if (!dfsRes) {
				return false;
			}
		}
		return true;
	};
	
	stk.emplace_back(0, -1);
	bool dfsRes = dfs(0, 0);
	stk.pop_back();
	
	if (dfsRes) {
		loop.emplace_back(0, -1);
	}
	
	vector<char> used(n, false);
	for (auto i: loop) {
		used[i.first] = true;
	}
	
	function<void(int, int, int)> dfs2 = [&](int v, int p, int peid) {
		for (Edge edg: g[v]) {
			if (edg.dst == p || used[edg.dst]) {
				continue;
			}
			used[edg.dst] = true;
			dfs2(edg.dst, v, edg.idx);
		}
		if (peid >= 0) {
			edgify(peid, w[v]);
		}
	};
	
	for (auto i: loop) {
		dfs2(i.first, -1, -1);
	}
	
	if (dfsRes) {
		if (w[loop.back().first] != 0) {
			cout << "NO\n";
			return 0;
		}
	} else {
		int64_t soom = 0;
		for (auto i: loop) {
			soom += w[i.first];
		}
		assert(soom % 2 == 0);
		soom /= 2;
		int64_t e0 = soom;
		for (int i = 2; i < (int)loop.size(); i += 2) {
			e0 -= w[loop[i].first];
		}
		edgify(loop[0].second, e0);
		for (int i = 1; i < (int)loop.size(); i++) {
			edgify(loop[i].second, w[loop[i].first]);
		}
	}
	
	cout << "YES\n";
	for (int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}