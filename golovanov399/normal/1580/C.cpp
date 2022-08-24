#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

// #define TEST

const int K = 300;
const int N = 222222;
int p[N];
int small[K][K];

void solve() {
#ifdef TEST
	int n = 200'000, m = 200'000;
#else
	int n = nxt(), m = nxt();
#endif
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
#ifdef TEST
		int sum = rand() % (K - 3);
		a[i].first = rand() % (sum + 1) + 1;
		a[i].second = sum + 2 - a[i].first;
#else
		a[i].first = nxt();
		a[i].second = nxt();
#endif
	}
	vector<int> last_added(n, -1);
	int cur = 0;
	for (int i = 0; i < m; ++i) {
		cur += p[i];
#ifdef TEST
		int k = rand() % n;
		int type = (last_added[k] == -1) ? 1 : 2;
#else
		int type = nxt(), k = nxt() - 1;
#endif
		int sign = (type == 1 ? 1 : -1);
		auto [x, y] = a[k];
		if (x + y < K) {
			int t = (type == 1) ? i : last_added[k];
			const int sum = x + y;
			t %= sum;
			t += x;
			if (t >= sum) {
				t -= sum;
			}
			for (int j = 0; j < y; ++j) {
				small[sum][t] += sign;
				t += 1;
				if (t == sum) {
					t -= sum;
				}
			}
		} else {
			for (int t = (type == 1 ? i : last_added[k]); t < m; t += x + y) {
				if (t + x < m) {
					p[t + x] += sign;
					if (t + x <= i) {
						cur += sign;
					}
				}
				if (t + x + y < m) {
					p[t + x + y] -= sign;
					if (t + x + y <= i) {
						cur -= sign;
					}
				}
			}
		}
		last_added[k] = (type == 1) ? i : -1;

		int ans = cur;
		for (int j = 1; j < K; ++j) {
			ans += small[j][i % j];
		}
		assert(ans >= 0);
		printf("%d\n", ans);
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}