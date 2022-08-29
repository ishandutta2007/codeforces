#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> b(n);
	generate(all(b), nxt);

	// a[i] can turn to b[j] <=> a[i] <= b[j] and a(-i) <<= b(-j)
	// a[i] <= b[j]
	// a[0] <= b[0], ...,
	// i < j:
	//   a[i + 1] <= b[i]
	//   a[i + 2] <= b[i + 1]
	//   ...
	//   a[j] <= b[j - 1]
	// i > j:
	//   a[j] <= b[j + 1]
	//   ...
	//   a[i - 1] <= b[i]
	for (int i = 0, j = 0; i < n; ++i) {
		while (a[i] > b[j]) {
			++j;
		}
		cout << b[j] - a[i] << " ";
	}
	cout << "\n";
	for (int i = 0, j = 0; i < n; ++i) {
		if (j < i) {
			j = i;
		}
		while (j + 1 < n && a[j + 1] <= b[j]) {
			++j;
		}
		cout << b[j] - a[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}