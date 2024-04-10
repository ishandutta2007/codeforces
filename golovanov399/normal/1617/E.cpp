#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Node {
	set<int> to;
	int idx;

	Node(): to(), idx(-1) {}
};

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	map<int, Node> M;
	M[0] = Node{};

	for (int i = 0; i < n; ++i) {
		vector<int> path;
		int x = a[i];
		int d = (1 << 30);
		while (x) {
			path.push_back(x);
			while (d / 2 >= x) {
				d /= 2;
			}
			x = d - x;
		}
		reverse(all(path));
		for (int y : path) {
			M[x].to.insert(y);
			x = y;
		}
		M[x].idx = i;
	}

	array<int, 3> ans = {0, 0, 0};
	function<pair<int, int>(int)> rec = [&](int v) {
		auto nd = M[v];
		pair<int, int> res = {0, nd.idx};
		if (nd.idx == -1) {
			res.first = -1e9;
		}
		for (int x : nd.to) {
			auto tmp = rec(x);
			tmp.first += 1;
			ans = max(ans, {res.first + tmp.first, res.second, tmp.second});
			res = max(res, tmp);
		}
		return res;
	};
	rec(0);
	cout << ans[1] + 1 << " " << ans[2] + 1 << " " << ans[0] << "\n";

	return 0;
}