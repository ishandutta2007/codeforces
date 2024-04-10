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
	int m = *min_element(all(a));
	int cnt = 0;
	for (int x : a) {
		if (x > m) {
			++cnt;
		}
	}

	if (cnt >= n / 2) {
		cout << "Alice\n";
	} else {
		cout << "Bob\n";
	}

	return 0;
}