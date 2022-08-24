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

	int n = nxt(), m = nxt(), l = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	set<int> S;
	S.insert(-1);
	S.insert(n);
	for (int i = 0; i < n; ++i) {
		if (a[i] <= l) {
			S.insert(i);
		}
	}

	int ans = 0;
	int lst = -2;
	for (int x : S) {
		if (x > lst + 1) {
			++ans;
		}
		lst = x;
	}

	while (m--) {
		int t = nxt();
		if (t == 0) {
			printf("%d\n", ans);
		} else {
			int p = nxt() - 1, d = nxt();
			bool ok = (a[p] <= l);
			a[p] += d;
			ok &= (a[p] > l);
			if (ok) {
				auto it = S.find(p);
				if (p > *prev(it) + 1) {
					--ans;
				}
				if (*next(it) > p + 1) {
					--ans;
				}
				++ans;
				S.erase(p);
			}
		}
	}

	return 0;
}