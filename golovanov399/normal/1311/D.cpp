#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline long long nxt() {
	long long x;
	cin >> x;
	return x;
}

vector<array<int, 3>> opts;

void solve() {
	array<int, 3> a;
	generate(all(a), nxt);
	pair<int, array<int, 3>> ans = {1111111, {}};
	for (const auto& b : opts) {
		int cur = 0;
		for (int i = 0; i < 3; ++i) {
			cur += abs(b[i] - a[i]);
		}
		ans = min(ans, {cur, b});
	}
	cout << ans.first << "\n";
	for (auto x : ans.second) {
		cout << x << " ";
	}
	cout << "\n";
}

const int N = 11111;

int main() {
	for (int a = 1; a < N; ++a) {
		for (int b = a; b < N; b += a) {
			for (int c = b; c < N; c += b) {
				opts.push_back({a, b, c});
			}
		}
	}

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}