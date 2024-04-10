#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 111111;
vector<int> a[N], b[N];

int dp[2][N];

int main() {
	int n = nxt();
	[[maybe_unused]] int m = nxt();
	for (int i = 0; i < n; ++i) {
		int c = nxt();
		while (c--) {
			int u = i, v = nxt() - 1;
			a[u].push_back(v);
			b[v].push_back(u);
		}
	}

	int s = nxt() - 1;

	memset(dp, -1, sizeof(dp));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		if (a[i].empty()) {
			q.push({0, i});
		}
	}
	while (!q.empty()) {
		auto [t, v] = q.front();
		q.pop();


		t ^= 1;
		for (int x : b[v]) {
			if (dp[t][x] > -1) {
				continue;
			}
			dp[t][x] = v;
			q.push({t, x});
		}
	}

	if (dp[1][s] > -1) {
		printf("Win\n");
		int t = 1;
		while (s > -1) {
			printf("%d ", s + 1);
			s = dp[t][s];
			t ^= 1;
		}
		printf("\n");
	} else {
		vector<char> used(n, 0);
		function<void(int)> dfs = [&](int v) {
			used[v] = 1;
			for (int x : a[v]) {
				if (used[x] == 1) {
					printf("Draw\n");
					exit(0);
				} else if (used[x] == 0) {
					dfs(x);
				}
			}
			used[v] = 2;
		};
		dfs(s);
		puts("Lose");
	}

	return 0;
}