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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[nxt() - 1] = i;
	}

	vector<int> b(n);
	int cnt = 0;
	int mn = 0;
	vector<char> used(n + 1);
	for (int i = 0; i < n; ++i) {
		b[i] = a[nxt() - 1];
		if (mn < b[i]) {
			++cnt;
		}
		used[b[i]] = 1;
		while (used[mn]) {
			++mn;
		}
	}

	cout << cnt << "\n";

	return 0;
}