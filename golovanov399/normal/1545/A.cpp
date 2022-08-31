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
	vector<itn> a(n);
	generate(all(a), nxt);
	auto b = a;
	sort(all(b));
	map<pair<int, int>, int> M;
	for (int i = 0; i < n; ++i) {
		M[{b[i], i % 2}] += 1;
	}
	for (int i = 0; i < n; ++i) {
		M[{a[i], i % 2}] -= 1;
	}
	for (auto p : M) {
		if (p.second) {
			cout << "No\n";
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