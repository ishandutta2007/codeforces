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

void solve() {
	int n = nxt();
	vector<int> nx(n);
	for (int i = 0; i < n; ++i) {
		nx[i] = nxt();
		if (nx[i] > -1) {
			--nx[i];
		}
	}

	for (int i = 0; i < n; ++i) {
		if (nx[i] == -1) {
			nx[i] = i + 1;
		}
	}
	set<int> S;
	for (int i = 0; i < n; ++i) {
		while (!S.empty() && *S.begin() <= i) {
			S.erase(S.begin());
		}
		if (!S.empty() && *S.begin() < nx[i]) {
			printf("-1\n");
			return;
		}
		S.insert(nx[i]);
	}
	vector<pair<int, int>> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = {-nx[i], i};
	}
	sort(all(ar));
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[ar[i].second] = n - i;
	}
	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}