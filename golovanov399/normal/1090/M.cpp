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

int main() {
	int n = nxt();
	[[maybe_unused]] int k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	int ans = 0;
	int cur = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] != a[i + 1]) {
			cur += 1;
		} else {
			cur = 0;
		}
		ans = max(ans, cur);
	}
	cout << ans + 1 << "\n";

	return 0;
}