
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

void solve() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	int idx = max_element(all(a)) - a.begin();
	int l = idx - 1, r = idx + 1;
	for (int i = 1; i < n; ++i) {
		if (l >= 0 && a[l] == n - i) {
			--l;
		} else if (r < n && a[r] == n - i) {
			++r;
		} else {
			cout << "NO\n";
			return;
		}
	}
	puts("YES");
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}