#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	vector<int> b(n);
	generate(all(b), nxt);
	auto total = accumulate(all(b), 0ll);
	long long t = 1ll * n * (n + 1) / 2;
	if (total % t) {
		cout << "NO\n";
		return;
	}
	long long s = total / t;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		long long diff = b[(i + 1) % n] - b[i];
		long long cur = diff - s;
		if (cur >= 0 || cur % n) {
			cout << "NO\n";
			return;
		}
		a[(i + 1) % n] = -cur / n;
	}
	cout << "YES\n";
	for (auto x : a) {
		cout << x << " ";
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