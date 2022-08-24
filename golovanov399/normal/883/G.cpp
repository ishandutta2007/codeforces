#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Edge {
	int from, to;
	int id;
	bool dir;
};

int main() {
	int n = nxt(), m = nxt(), s = nxt() - 1;
	vector<Edge> edges;
	vector<vector<Edge>> a(n);
	for (int i = 0; i < m; ++i) {
		int t = nxt(), u = nxt() - 1, v = nxt() - 1;
		edges.push_back({u, v, i, t == 1});
		a[u].push_back(edges.back());
		if (t > 1) {
			a[v].push_back({v, u, i, false});
		}
	}
	vector<int> num(m, 0);
	int cur = 0;
	for (int i = 0; i < m; ++i) {
		if (!edges[i].dir) {
			num[i] = cur++;
		}
	}
	string ans = string(cur, '+');

	int val = 0;
	vector<char> used(n);
	vector<int> st = {s};
	used[s] = 1;
	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		++val;
		for (auto e : a[v]) {
			if (used[e.to]) {
				continue;
			}
			used[e.to] = 1;
			st.push_back(e.to);
			if (!e.dir) {
				ans[num[e.id]] = (e.from == edges[e.id].from ? '+' : '-');
			}
		}
	}
	printf("%d\n", val);
	puts(ans.c_str());

	val = 0;
	used.assign(n, 0);
	used[s] = 1;
	st = {s};
	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		++val;
		for (auto e : a[v]) {
			if (used[e.to]) {
				continue;
			}
			if (!e.dir) {
				ans[num[e.id]] = (edges[e.id].to == v ? '+' : '-');
				continue;
			}
			used[e.to] = 1;
			st.push_back(e.to);
		}
	}

	printf("%d\n", val);
	puts(ans.c_str());

	return 0;
}