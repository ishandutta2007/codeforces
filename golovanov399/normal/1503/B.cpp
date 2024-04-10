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

int main() {
	int n = nxt();
	vector<pair<int, int>> par[2];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			par[(i + j) % 2].push_back({i, j});
		}
	}
	for (int i = 0; i < n * n; ++i) {
		int a = nxt() - 1;
		if (par[0].empty() || par[1].empty()) {
			int c = 0;
			while ((c < 2 && par[c].empty()) || c == a) {
				++c;
			}
			vector<pair<int, int>>& q = (par[0].empty() ? par[1] : par[0]);
			auto [x, y] = q.back();
			q.pop_back();
			cout << c + 1 << " " << x + 1 << " " << y + 1 << endl;
		} else {
			int c = 0;
			if (c == a) {
				++c;
			}
			vector<pair<int, int>>& q = par[c];
			auto [x, y] = q.back();
			q.pop_back();
			cout << c + 1 << " " << x + 1 << " " << y + 1 << endl;
		}
	}

	return 0;
}