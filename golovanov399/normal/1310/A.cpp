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
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
	}
	for (int i = 0; i < n; ++i) {
		a[i].second = nxt();
	}
	sort(all(a));

	long long ans = 0;
	priority_queue<int> S;
	long long income = 0;
	for (int i = 0, cur = 0; i < n || !S.empty();) {
		if (i < n && S.empty() && cur < a[i].first) {
			cur = a[i].first;
		}
		while (i < n && a[i].first == cur) {
			S.push(a[i].second);
			income += a[i].second;
			++i;
		}
		++cur;
		income -= S.top();
		S.pop();
		ans += income;
	}

	cout << ans << "\n";

	return 0;
}