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

const int N = 2222;
const int L = 9;

vector<array<int, 4>> masks;

int dp[N][715][L];

struct State {
	int pref;
	int mask;
	int cur;
};

int decode[L + 1][L + 1][L + 1][L + 1];

inline bool has(int mask, int i) {
	return find(all(masks[mask]), i) != masks[mask].end();
}

int add(int mask, int i) {
	assert(masks[mask][3] == -1);
	auto v = masks[mask];
	int j = 3;
	while (j && v[j - 1] < i) {
		v[j] = v[j - 1];
		--j;
	}
	v[j] = i;
	return decode[v[0] + 1][v[1] + 1][v[2] + 1][v[3] + 1];
}

int rem(int mask, int i) {
	auto v = masks[mask];
	int j = find(all(v), i) - v.begin();
	while (j < 3) {
		v[j] = v[j + 1];
		++j;
	}
	v[j] = -1;
	return decode[v[0] + 1][v[1] + 1][v[2] + 1][v[3] + 1];
}

int main() {
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < L + 1; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k <= j; ++k) {
				for (int l = 0; l <= k; ++l) {
					masks.push_back({i - 1, j - 1, k - 1, l - 1});
				}
			}
		}
	}
	for (int i = 0; i < (int)masks.size(); ++i) {
		decode[masks[i][0] + 1][masks[i][1] + 1][masks[i][2] + 1][masks[i][3] + 1] = i;
	}

	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt() - 1, a[i].second = nxt() - 1;
	}

	dp[0][0][0] = 0;
	queue<State> q;
	q.push({0, 0, 0});

	while (!q.empty()) {
		auto st = q.front();
		q.pop();

		vector<State> cands;
		if (st.cur) {
			cands.push_back({st.pref, st.mask, st.cur - 1});
		}
		if (st.cur < L - 1) {
			cands.push_back({st.pref, st.mask, st.cur + 1});
		}
		if (has(st.mask, st.cur)) {
			cands.push_back({st.pref, rem(st.mask, st.cur), st.cur});
		}
		if (st.pref < n && a[st.pref].first == st.cur && masks[st.mask][3] == -1) {
			cands.push_back({st.pref + 1, add(st.mask, a[st.pref].second), st.cur});
		}

		for (auto ns : cands) {
			if (dp[ns.pref][ns.mask][ns.cur] != -1) {
				continue;
			}
			q.push(ns);
			dp[ns.pref][ns.mask][ns.cur] = dp[st.pref][st.mask][st.cur] + 1;
		}
	}

	// for (int i = 0; i <= n; ++i) {
	// 	for (int j = 0; j < (int)masks.size(); ++j) {
	// 		for (int k = 0; k < L; ++k) {
	// 			if (dp[i][j][k] == -1) {
	// 				continue;
	// 			}
	// 			cerr << i << " guys, " << "{";
	// 			bool fp = 1;
	// 			for (int x : masks[j]) {
	// 				if (x == -1) {
	// 					break;
	// 				}
	// 				if (!fp) {
	// 					cerr << ", ";
	// 				}
	// 				fp = 0;
	// 				cerr << x;
	// 			}
	// 			cerr << "}, currently at floor " << k + 1 << ": " << dp[i][j][k] << "\n";
	// 		}
	// 	}
	// }

	int ans = 1e9;
	for (int i = 0; i < L; ++i) {
		ans = min(ans, dp[n][0][i]);
	}
	printf("%d\n", ans);

	return 0;
}