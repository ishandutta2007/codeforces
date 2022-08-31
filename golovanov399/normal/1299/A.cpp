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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	for (int b = 30; b >= 0; --b) {
		vector<int> g;
		for (int i = 0; i < n; ++i) {
			if (a[i] & (1 << b)) {
				g.push_back(i);
			}
		}
		if ((int)g.size() == 1) {
			cout << a[g[0]];
			for (int i = 0; i < n; ++i) {
				if (i != g[0]) {
					cout << " " << a[i];
				}
			}
			cout << "\n";
			return 0;
		}
	}

	for (int x : a) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}