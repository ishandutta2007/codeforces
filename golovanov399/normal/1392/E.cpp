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
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int N = 30;
long long a[N][N];

void play(int n) {
	long long x;
	cin >> x;
	vector<pair<int, int>> ans = {{0, 0}};
	x >>= 1;
	int i = 0, j = 0;
	while (i < n - 1 || j < n - 1) {
		if (x % 2 == i % 2) {
			++j;
		} else {
			++i;
		}
		ans.push_back({i, j});
		x >>= 1;
	}
	for (auto [i, j] : ans) {
		cout << i + 1 << " " << j + 1 << "\n";
	}
	cout.flush();
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = ((long long)(i % 2)) << (i + j);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	int q = nxt();
	while (q--) {
		play(n);
	}

	return 0;
}