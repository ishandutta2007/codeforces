#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
		a[i].second = nxt();
	}

	while (true) {
		map<int, vector<int>> rems;
		for (int i = 0; i < n; ++i) {
			rems[abs(a[i].first + a[i].second) % 2].push_back(i);
		}
		if (rems.size() == 1) {
			for (auto& [x, y] : a) {
				if (abs(x + y) % 2) {
					x -= 1;
				}
				int q = (x + y) / 2;
				int w = (x - y) / 2;
				x = q;
				y = w;
			}
			continue;
		}
		cout << rems[0].size() << "\n";
		for (int x : rems[0]) {
			cout << x + 1 << " ";
		}
		cout << "\n";
		return 0;
	}

	return 0;
}