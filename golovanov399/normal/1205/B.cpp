#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	{
		sort(all(a));
		int idx = upper_bound(all(a), 0ll) - a.begin();
		a.erase(a.begin(), a.begin() + idx);
		n = a.size();
	}
	vector<int> cnt(100);
	for (auto x : a) {
		for (int i = 0; i < 60; ++i) {
			if ((x >> i) & 1ll) {
				cnt[i] += 1;
			}
		}
	}
	if (*max_element(all(cnt)) >= 3) {
		printf("3\n");
		return 0;
	}

	vector<vector<int>> ed(n);
	for (int i = 0; i < 60; ++i) {
		long long b = 1ll << i;
		int lst = -1;
		for (int j = 0; j < n; ++j) {
			if (a[j] & b) {
				if (lst > -1) {
					ed[lst].push_back(j);
					ed[j].push_back(lst);
				}
				lst = j;
			}
		}
	}
	for (auto& v : ed) {
		make_unique(v);
	}

	auto getCycle = [&](int v) {
		vector<int> d(n, -1);
		d[v] = 0;
		int ans = 1e9;
		queue<int> q;
		q.push(v);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int x : ed[u]) {
				if (d[x] == -1) {
					d[x] = d[u] + 1;
					q.push(x);
				} else if (d[x] >= d[u]) {
					ans = min(ans, d[u] + d[x] + 1);
				}
			}
		}
		return ans;
	};

	int ans = 1e9;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, getCycle(i));
	}

	if (ans > n) {
		ans = -1;
	}
	cout << ans << "\n";

	return 0;
}