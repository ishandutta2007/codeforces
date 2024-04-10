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

const int N = 10111;
const int M = 1111;
int dp[N * M];

int st[2][N * M];
int sz[2];

bool empty(int t = 0) {
	return sz[t] == 0;
}

int back(int t = 0) {
	return st[t][sz[t] - 1];
}

void pop_back(int t = 0) {
	--sz[t];
}

void push_back(int t, int x) {
	st[t][sz[t]++] = x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	nxt();
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	int g = nxt(), r = nxt();

	memset(dp, -1, sizeof(dp));
	dp[g] = 0;
	push_back(0, g);
	while (!empty()) {
		int d = dp[back()];
		while (!empty()) {
			int idx = back();
			pop_back();
			if (dp[idx] != d) {
				continue;
			}
			int i = idx / (g + 1), x = idx % (g + 1);

			if (x == 0) {
				if (dp[idx + g] == -1) {
					dp[idx + g] = d + 1;
					push_back(1, idx + g);
				}
			} else {
				if (i > 0 && a[i] - a[i - 1] <= x) {
					int nidx = (i - 1) * (g + 1) + (x - a[i] + a[i - 1]);
					if (dp[nidx] == -1) {
						dp[nidx] = d;
						push_back(0, nidx);
					}
				}
				if (i < n - 1 && a[i + 1] - a[i] <= x) {
					int nidx = (i + 1) * (g + 1) + (x - a[i + 1] + a[i]);
					if (dp[nidx] == -1) {
						dp[nidx] = d;
						push_back(0, nidx);
					}
				}
			}
		}
		for (int i = 0; i < sz[1]; ++i) {
			st[0][i] = st[1][i];
		}
		sz[0] = sz[1];
		sz[1] = 0;
	}

	long long ans = -1;
	for (int i = 0; i <= g; ++i) {
		if (dp[(n - 1) * (g + 1) + i] > -1) {
			if (ans == -1 || ans > 1ll * dp[(n - 1) * (g + 1) + i] * (r + g) + g - i) {
				ans = 1ll * dp[(n - 1) * (g + 1) + i] * (r + g) + g - i;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}