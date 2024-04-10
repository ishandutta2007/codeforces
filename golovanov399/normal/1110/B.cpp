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

	int n = nxt(), m = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	k = min(k, n);

	int ans = a.back() - a[0] + 1;
	for (int i = n - 1; i > 0; --i) {
		a[i] -= a[i - 1] + 1;
	}
	a.erase(a.begin());
	sort(all(a));
	k -= 1;
	reverse(all(a));
	for (int i = 0; i < k; ++i) {
		ans -= a[i];
	}

	cout << ans << "\n";

	return 0;
}