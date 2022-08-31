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
	if (all_of(all(a), [&](int x) { return x == 1; })) {
		cout << "NO\n";
		return;
	}
	if (all_of(all(a), [&](int x) { return x == 0; })) {
		cout << "YES\n";
		cout << "0\n";
		return;
	}
	if (count(all(a), 1) % 2) {
		cout << "NO\n";
		return;
	}

	vector<int> ans;
	auto press = [&](int i) {
		assert(0 < i && i < n - 1);
		ans.push_back(i);
		int x = a[i - 1] ^ a[i] ^ a[i + 1];
		a[i - 1] = a[i] = a[i + 1] = x;
	};

	vector<int> ones;
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			ones.push_back(i);
		}
	}
	assert((int)ones.size() % 2 == 0);
	for (int i = 0; i < (int)ones.size(); i += 2) {
		int x = ones[i], y = ones[i + 1];
		if (x % 2 == y % 2) {
			for (int k = x + 1; k < y; k += 2) {
				press(k);
			}
			for (int k = y - 3; k > x; k -= 2) {
				press(k);
			}
		} else if (x > 0 && a[x - 1] == 0) {
			for (int k = x + 1; k < y; k += 2) {
				press(k);
				press(k - 1);
			}
			press(y - 1);
		} else if (y < n - 1 && a[y + 1] == 0) {
			for (int k = y - 1; k > x; k -= 2) {
				press(k);
				press(k + 1);
			}
			press(x + 1);
		}
	}

	ones.clear();
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			ones.push_back(i);
		}
	}
	assert((int)ones.size() % 2 == 0);
	reverse(all(ones));
	for (int i = 0; i < (int)ones.size(); i += 2) {
		int x = ones[i + 1], y = ones[i];
		if (x % 2 == y % 2) {
			for (int k = x + 1; k < y; k += 2) {
				press(k);
			}
			for (int k = y - 3; k > x; k -= 2) {
				press(k);
			}
		} else if (x > 0 && a[x - 1] == 0) {
			for (int k = x + 1; k < y; k += 2) {
				press(k);
				press(k - 1);
			}
			press(y - 1);
		} else if (y < n - 1 && a[y + 1] == 0) {
			for (int k = y - 1; k > x; k -= 2) {
				press(k);
				press(k + 1);
			}
			press(x + 1);
		}
	}

	if (any_of(all(a), [&](int x) { return x == 1; })) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans.size() << "\n";
		for (int x : ans) {
			cout << x << " ";
		}
		cout << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}