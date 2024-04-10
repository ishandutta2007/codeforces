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
	vector<long long> a(n);
	for (int i = 1; i < n; i += 2) {
		a[i] = nxt();
	}
	vector<long long> x(n);

	int lst = 0;
	for (int i = 1; i < n; i += 2) {
		int y = a[i];
		int g = -1;
		for (int j = 1; j * j < y; ++j) {
			if (y % j) {
				continue;
			}
			if (j % 2 != y / j % 2) {
				continue;
			}
			int mn = (y / j - j) / 2;
			if (mn > lst) {
				g = j;
			}
		}
		if (g == -1) {
			cout << "No\n";
			return 0;
		}
		x[i - 1] = (y / g - g) / 2;
		lst = x[i] = (y / g + g) / 2;
	}

	printf("Yes\n");
	for (int i = 0; i < n; ++i) {
		a[i] = x[i] * x[i];
		if (i) {
			a[i] -= x[i - 1] * x[i - 1];
		}
		printf("%lld ", a[i]);
	}
	printf("\n");

	return 0;
}