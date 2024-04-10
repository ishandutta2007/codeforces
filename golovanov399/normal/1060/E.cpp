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

const int N = 222222;
vector<int> a[N];

long long ans = 0;
struct Shit {
	int cnt;
	long long sum;

	Shit(int _cnt, long long _sum): cnt(_cnt), sum(_sum) {}

	Shit() {
		cnt = 0;
		sum = 0;
	}
};

array<Shit, 3> dfs(int v, int p = -1) {
	Shit to_all, to_odd, to_even;
	to_all.cnt = 1;
	to_even.cnt = 1;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}

		auto resp = dfs(x, v);
		for (auto& shit : resp) {
			shit.sum += shit.cnt;
		}

		ans += to_all.cnt * resp[0].sum + to_all.sum * resp[0].cnt;
		ans += 1ll * to_odd.cnt * resp[1].cnt;
		ans += 1ll * to_even.cnt * resp[2].cnt;

		to_all = {to_all.cnt + resp[0].cnt, to_all.sum + resp[0].sum};
		to_odd = {to_odd.cnt + resp[2].cnt, to_odd.sum + resp[2].sum};
		to_even = {to_even.cnt + resp[1].cnt, to_even.sum + resp[1].sum};
	}
	return {to_all, to_odd, to_even};
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0);
	cout << ans / 2 << "\n";

	return 0;
}