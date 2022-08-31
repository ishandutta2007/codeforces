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
		a[i] = nxt();
	}

	a.insert(a.begin(), 0);
	for (int i = n; i >= 1; --i) {
		a[i] -= a[i - 1];
	}

	a.erase(a.begin());
	vector<int> ans;
	for (int k = 1; k <= n; ++k) {
		bool ok = true;
		for (int i = 0; i + k < n; ++i) {
			if (a[i + k] != a[i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans.push_back(k);
		}
	}
	printf("%d\n", (int)ans.size());
	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}