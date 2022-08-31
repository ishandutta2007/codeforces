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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Guy {
	long long a;
	int cnt;
	long long b;
};

int main() {
	int n = nxt();
	vector<pair<long long, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i].second;
	}
	map<long long, long long> M;
	map<long long, int> cnt;
	for (int i = 0; i < n; ++i) {
		M[a[i].first] += a[i].second;
		cnt[a[i].first] += 1;
	}
	vector<Guy> guys;
	for (const auto& [k, v] : M) {
		guys.push_back({k, cnt[k], v});
	}
	
	int sz = guys.size();
	vector<char> used(sz, 0);
	for (int i = (int)sz - 1; i >= 0; --i) {
		if (guys[i].cnt > 1) {
			used[i] = 1;
		}
		if (used[i]) {
			for (int j = 0; j < i; ++j) {
				if ((guys[j].a & guys[i].a) == guys[j].a) {
					used[j] = 1;
				}
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < sz; ++i) {
		if (used[i]) {
			ans += guys[i].b;
		}
	}
	cout << ans << "\n";

	return 0;
}