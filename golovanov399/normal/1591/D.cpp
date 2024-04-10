#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

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

	if (is_sorted(all(a))) {
		cout << "YES\n";
		return;
	}
	if (n == 2) {
		cout << "NO\n";
		return;
	}

	for (auto& x : a) {
		x -= 1;
	}

	vector<int> b(n, -1);
	for (int i = 0; i < n; ++i) {
		if (b[a[i]] > -1) {
			cout << "YES\n";
			return;
		}
		b[a[i]] = i;
	}
	int par = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != i) {
			int j = b[i];
			swap(a[i], a[j]);
			swap(b[a[i]], b[a[j]]);
			par ^= 1;
		}
	}
	cout << (par ? "NO" : "YES") << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}