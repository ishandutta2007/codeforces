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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<long long> pos(n), neg(n);
	for (int i = 1; i < n; ++i) {
		pos[i] = pos[i - 1] + max(0, a[i] - a[i - 1]);
		neg[i] = neg[i - 1] + min(0, a[i] - a[i - 1]);
	}
	{
		long long x = -neg.back();
		for (auto& y : neg) {
			y += x;
		}
	}
	if (pos[0] + neg[0] > a[0]) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}