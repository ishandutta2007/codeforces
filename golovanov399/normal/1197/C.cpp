
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
	int n = nxt(), k = nxt();
	vector<itn> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	vector<int> b;
	for (int i = 1; i < n; ++i) {
		b.push_back(a[i] - a[i - 1]);
	}
	sort(all(b));
	reverse(all(b));
	b.resize(k - 1);
	cout << a.back() - a[0] - accumulate(all(b), 0ll) << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}