#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), q = nxt();
	vector<int> first(n, q), last(n, -1);
	for (int i = 0; i < q; ++i) {
		int x = nxt() - 1;
		last[x] = i;
		first[x] = min(first[x], i);
	}

	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		int x = i, y = i + 1;
		for (char c : ")") {
			if (first[x] > last[y]) {
				++ans;
			}
			swap(x, y);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (last[i] == -1) {
			++ans;
		}
	}

	cout << ans << "\n";

	return 0;
}