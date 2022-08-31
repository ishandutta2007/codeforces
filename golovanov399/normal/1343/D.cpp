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
	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
	}
	vector<int> p(2 * k);
	for (int i = 0; i < n / 2; ++i) {
		int x = a[i], y = a[n - 1 - i];
		int l = min(x, y);
		int r = max(x + k - 1, y + k - 1);
		p[0] += 2;
		p[l] -= 1;
		p[x + y] -= 1;
		p[x + y + 1] += 1;
		p[r + 1] += 1;
	}
	for (int i = 1; i < (int)p.size(); ++i) {
		p[i] += p[i - 1];
	}
	cout << *min_element(all(p)) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}