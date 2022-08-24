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

const int N = 333'333;
struct Edge {
	int u;
	int v;
	int w;
	int id;

	int other(int x) const {
		return u == x ? v : u;
	}
};

vector<Edge> one[N];
vector<Edge> two[N];
Edge edges[N];

int parity[N];
char edge_used[N];
int where[N];

void clear_ones(int v) {
	while (!one[v].empty() && edge_used[one[v].back().id]) {
		one[v].pop_back();
	}
}

void clear_twos(int v) {
	while (!two[v].empty() && edge_used[two[v].back().id]) {
		two[v].pop_back();
	}
}

void orient(int id, int v) {
	edge_used[id] = true;
	where[id] = v;
}

struct Path {
	int from, to;
	vector<int> ids;

	void reverse() {
		swap(from, to);
		::reverse(all(ids));
	}

	void orient() const {
		int v = from;
		for (int id : ids) {
			v = edges[id].other(v);
			::orient(id, v);
		}
	}
};

void solve() {
	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		edges[i] = {u, v, w, i};
		if (w == 1) {
			one[u].push_back({u, v, w, i});
			one[v].push_back({v, u, w, i});
		} else {
			two[u].push_back({u, v, w, i});
			two[v].push_back({v, u, w, i});
		}
		parity[u] ^= (w % 2);
		parity[v] ^= (w % 2);
	}
	{
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += parity[i];
		}
		cout << ans << "\n";
	}

	vector<Path> one_paths;

	for (int i = 0; i < n; ++i) {
		if (!parity[i]) {
			continue;
		}
		parity[i] ^= 1;
		int v = i;
		Path path = {i, i, {}};
		while (!parity[v]) {
			clear_ones(v);
			path.ids.push_back(one[v].back().id);
			orient(one[v].back().id, one[v].back().v);
			v = one[v].back().v;
			path.to = v;
		}
		parity[v] ^= 1;
		one_paths.push_back(path);
	}

	auto add_one_cycle = [&](int start) {
		int v = start;
		do {
			clear_ones(v);
			orient(one[v].back().id, one[v].back().v);
			v = one[v].back().v;
		} while (v != start);
	};

	for (int i = 0; i < n; ++i) {
		while (true) {
			clear_ones(i);
			if (one[i].empty()) {
				break;
			}
			add_one_cycle(i);
		}
	}

	vector<Path> two_paths;
	for (int i = 0; i < n; ++i) {
		parity[i] = two[i].size() % 2;
	}
	for (int i = 0; i < n; ++i) {
		if (!parity[i]) {
			continue;
		}
		parity[i] ^= 1;
		int v = i;
		Path path = {i, i, {}};
		while (!parity[v]) {
			clear_twos(v);
			path.ids.push_back(two[v].back().id);
			orient(two[v].back().id, two[v].back().v);
			v = two[v].back().v;
			path.to = v;
		}
		parity[v] ^= 1;
		two_paths.push_back(path);
	}

	auto add_two_cycle = [&](int start) {
		int v = start;
		do {
			clear_twos(v);
			orient(two[v].back().id, two[v].back().v);
			v = two[v].back().v;
		} while (v != start);
	};

	for (int i = 0; i < n; ++i) {
		while (true) {
			clear_twos(i);
			if (two[i].empty()) {
				break;
			}
			add_two_cycle(i);
		}
	}

	vector<int> vertex_used(n, false);
	vector<int> one_id(n, -1), two_id(n, -1);
	for (int i = 0; i < (int)one_paths.size(); ++i) {
		one_id[one_paths[i].from] = one_id[one_paths[i].to] = i;
		// cerr << one_paths[i].from << " " << one_paths[i].to << " -- " << i << "\n";
	}
	for (int i = 0; i < (int)two_paths.size(); ++i) {
		two_id[two_paths[i].from] = two_id[two_paths[i].to] = i;
		// cerr << two_paths[i].from << " " << two_paths[i].to << " -- " << i << "\n";
	}

	for (int i = 0; i < n; ++i) {
		if (vertex_used[i]) {
			continue;
		}
		if ((one_id[i] > -1) != (two_id[i] > -1)) {
			int v = i;
			int last = one_id[v] > -1 ? 1 : 2;
			while ((last == 1 ? one_id[v] : two_id[v]) > -1) {
				auto& path = last == 1 ? one_paths[one_id[v]] : two_paths[two_id[v]];
				if (path.from != v) {
					path.reverse();
				}
				vertex_used[v] = true;
				path.orient();
				v = path.to;
				last = 3 - last;
			}
			vertex_used[v] = true;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (vertex_used[i] || one_id[i] == -1) {
			continue;
		}

		int v = i;
		int last = 1;
		while (!vertex_used[v]) {
			auto& path = last == 1 ? one_paths[one_id[v]] : two_paths[two_id[v]];
			if (path.from != v) {
				path.reverse();
			}
			vertex_used[v] = true;
			path.orient();
			v = path.to;
			last = 3 - last;
		}
		vertex_used[v] = true;
	}

	assert(all_of(edge_used, edge_used + m, [](char x) { return x == true; }));
	string ans(m, '1');
	for (int i = 0; i < m; ++i) {
		if (where[i] != edges[i].v) {
			ans[i] = '2';
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}