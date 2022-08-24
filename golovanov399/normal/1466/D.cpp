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

void solve() {
	int n = nxt();
	vector<int> w(n);
	generate(all(w), nxt);
	vector<int> deg(n);
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		deg[u] += 1;
		deg[v] += 1;
	}
	vector<int> a;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += w[i];
		for (int j = 0; j < deg[i] - 1; ++j) {
			a.push_back(w[i]);
		}
	}
	sort(all(a));
	reverse(all(a));
	cout << ans;
	for (auto x : a) {
		ans += x;
		cout << " " << ans;
	}
	cout << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}