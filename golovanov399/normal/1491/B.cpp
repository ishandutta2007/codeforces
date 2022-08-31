#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), u = nxt(), v = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	for (int i = 0; i < n - 1; ++i) {
		if (abs(a[i + 1] - a[i]) >= 2) {
			cout << "0\n";
			return;
		}
	}
	if (*min_element(all(a)) == *max_element(all(a))) {
		cout << v + min(u, v) << "\n";
	} else {
		cout << min(u, v) << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}