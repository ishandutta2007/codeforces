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
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);

	auto check = [&](int x) {
		vector<int> b;
		for (int y : a) {
			if (y != x) {
				b.push_back(y);
			}
		}
		auto c = b;
		reverse(all(c));
		return b == c;
	};

	for (int i = 0; i < n - 1 - i; ++i) {
		if (a[i] != a[n - 1 - i]) {
			if (check(a[i]) || check(a[n - 1 - i])) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
			return;
		}
	}
	cout << "Yes\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}