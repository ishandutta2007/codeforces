#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

const int N = 1111111;

struct Shit {
	int city;
	int cost;
};

vector<Shit> in[N], out[N];

long long suf_cost[N];
long long pref_cost[N];

int main() {
	int n = nxt(), m = nxt(), k = nxt();
	for (int i = 0; i < m; ++i) {
		int d = nxt(), f = nxt(), t = nxt(), c = nxt();
		if (f == 0) {
			out[d].push_back({t - 1, c});
		} else {
			in[d].push_back({f - 1, c});
		}
	}

	long long total = 0;
	int cnt = 0;
	vector<int> cur_cost(n, 0);
	for (int i = N - 1; i >= 0; --i) {
		for (auto shit : out[i]) {
			if (cur_cost[shit.city] == 0) {
				cnt += 1;
			}

			if (cur_cost[shit.city] == 0 || cur_cost[shit.city] > shit.cost) {
				total -= cur_cost[shit.city];
				cur_cost[shit.city] = shit.cost;
				total += cur_cost[shit.city];
			}
		}
		suf_cost[i] = (cnt == n ? total : LLONG_MAX / 3);
	}

	total = 0;
	cnt = 0;
	cur_cost.assign(n, 0);
	for (int i = 0; i < N; ++i) {
		for (auto shit : in[i]) {
			if (cur_cost[shit.city] == 0) {
				cnt += 1;
			}

			if (cur_cost[shit.city] == 0 || cur_cost[shit.city] > shit.cost) {
				total -= cur_cost[shit.city];
				cur_cost[shit.city] = shit.cost;
				total += cur_cost[shit.city];
			}
		}
		pref_cost[i] = (cnt == n ? total : LLONG_MAX / 3);
	}

	long long ans = LLONG_MAX;
	for (int i = 0; i + k + 1 < N; ++i) {
		ans = min(ans, pref_cost[i] + suf_cost[i + k + 1]);
	}

	if (ans > 1e17) {
		puts("-1");
	} else {
		printf("%lld\n", ans);
	}

	return 0;
}