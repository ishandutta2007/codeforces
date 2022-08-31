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
	if (n % 2) {
		cout << "No\n";
		return;
	}
	sort(all(a));
	for (int i = 1; i < n / 2; ++i) {
		if (a[i] == a[i + n / 2 - 1]) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
	for (int i = 0; i < n / 2; ++i) {
		cout << a[i] << " " << a[i + n / 2] << " ";
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