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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	long long ans = 0;
	int l = 0;
	for (int i = 0; i < n; ++i) {
		if (i == l) {
			ans += a[i] / 3;
			a[i] %= 3;
			++l;
		}
		while (l < n) {
			int tmp = min(a[l] / 2, a[i]);
			ans += tmp;
			a[i] -= tmp;
			a[l] -= 2 * tmp;
			if (a[l] < 2) {
				++l;
			} else {
				break;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}