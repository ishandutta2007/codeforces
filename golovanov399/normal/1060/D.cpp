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

	int n = nxt();
	vector<int> l(n), r(n);
	for (int i = 0; i < n; ++i) {
		l[i] = nxt(), r[i] = nxt();
	}
	sort(all(l));
	sort(all(r));
	long long ans = accumulate(all(l), 0ll) + accumulate(all(r), 0ll);
	for (int i = 0; i < n; ++i) {
		ans += abs(l[i] - r[i]);
	}
	cout << ans / 2 + n << "\n";

	return 0;
}