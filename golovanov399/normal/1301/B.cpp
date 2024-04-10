#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> bitches;
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) {
			if (i + 1 < n && a[i + 1] > -1) {
				bitches.push_back(a[i + 1]);
			}
			if (i - 1 >= 0 && a[i - 1] > -1) {
				bitches.push_back(a[i - 1]);
			}
		}
	}
	int diff = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] > -1 && a[i + 1] > -1) {
			diff = max(diff, abs(a[i + 1] - a[i]));
		}
	}
	if (bitches.empty()) {
		cout << "0 228\n";
	} else {
		cout << max(diff, (*max_element(all(bitches)) - *min_element(all(bitches)) + 1) / 2) << " " << (*max_element(all(bitches)) + *min_element(all(bitches))) / 2 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}