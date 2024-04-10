#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = n - nxt();
	}
	vector<vector<int>> b(n + 1);
	for (int i = 0; i < n; ++i) {
		b[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (b[i].size() % i) {
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	int num = 0;
	vector<int> ans(n);
	for (int i = 1; i <= n; ++i) {
		while (!b[i].empty()) {
			if (b[i].size() % i == 0) {
				++num;
			}
			ans[b[i].back()] = num;
			b[i].pop_back();
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}