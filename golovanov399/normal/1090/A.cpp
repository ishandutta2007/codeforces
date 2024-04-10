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
	vector<vector<int>> a(n);
	int total_max = 0;
	for (int i = 0; i < n; ++i) {
		int k = nxt();
		a[i].resize(k);
		for (int& x : a[i]) {
			x = nxt();
		}
		total_max = max(total_max, *max_element(all(a[i])));
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += 1ll * (int)a[i].size() * (total_max - *max_element(all(a[i])));
	}
	cout << ans << "\n";

	return 0;
}