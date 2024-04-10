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
	vector<pair<int, int>> difs;
	for (int i = 0; i < n - 1; ++i) {
		difs.push_back({a[i + 1] - a[i], i});
	}
	sort(all(difs));
	reverse(all(difs));
	cout << "1";
	for (auto p : difs) {
		cout << " " << p.second + 2;
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}