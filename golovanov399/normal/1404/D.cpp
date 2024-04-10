#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

struct Edge {
	int to;
	int id;
};

int main() {
	int n = nxt();
	if (n % 2 == 0) {
		cout << "First" << endl;
		for (int i = 0; i < 2 * n; ++i) {
			cout << i % n + 1 << " ";
		}
		cout << endl;
	} else {
		cout << "Second" << endl;
		vector<vector<int>> edges(n);
		for (int i = 0; i < 2 * n; ++i) {
			edges[nxt() - 1].push_back(i);
		}
		vector<vector<Edge>> a(n);
		for (int i = 0; i < n; ++i) {
			a[edges[i][0] % n].push_back({edges[i][1] % n, i});
			a[edges[i][1] % n].push_back({edges[i][0] % n, i});
		}

		vector<char> used(n);
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				continue;
			}
			int pr = -1;
			for (int v = i; !used[v];) {
				int idx = 0;
				while (a[v][idx].id == pr) {
					++idx;
				}
				pr = a[v][idx].id;
				if (edges[pr][0] % n != v) {
					swap(edges[pr][0], edges[pr][1]);
				}
				used[v] = 1;
				v = a[v][idx].to;
			}
		}
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += edges[i][0];
			if (sum >= 2 * n) {
				sum %= 2 * n;
			}
		}
		if (!sum) {
			for (auto& v : edges) {
				swap(v[0], v[1]);
			}
		}
		for (auto p : edges) {
			cout << p[0] + 1 << " ";
		}
		cout << endl;
	}

	return 0;
}