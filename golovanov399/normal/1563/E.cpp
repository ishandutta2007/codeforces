#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

const int N = 1111;

vector<int> a[N];

long long dp[N];
char used[N];
char killed[N];

struct Gay {
	int need;
	int gives;
};

Gay gays[N];

int pr[N];

long long rollback(int v) {
	long long res = 0;
	while (!killed[v]) {
		res += gays[v].gives;
		killed[v] = true;
		v = pr[v];
	}
	return res;
}

long long dfs(int v) {
	for (int x : a[v]) {
		if (x == pr[v]) {
			continue;
		}
		if (killed[x] && !killed[v]) {
			return rollback(v);
		}
		if (killed[x] || gays[x].need >= dp[v]) {
			continue;
		}
		if (used[x]) {
			long long res = rollback(x);
			res += rollback(v);
			return res;
		} else {
			dp[x] = dp[v] + gays[x].gives;
			used[x] = true;
			pr[x] = v;
			if (auto res = dfs(x); res > 0) {
				return res;
			}
		}
	}
	return 0;
}

bool check(long long pwr, int n) {
	fill(killed, killed + n, 0);
	killed[0] = 1;
	while (true) {
		int killed_count = count(killed, killed + n, 1);
		if (killed_count == n) {
			return true;
		}
		fill(pr, pr + n, -1);
		fill(used, used + n, 0);
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			if (killed[i] && !used[i]) {
				used[i] = 1;
				dp[i] = pwr;
				if (auto income = dfs(i); income) {
					ok = true;
					pwr += income;
				}
			}
		}
		if (!ok) {
			return false;
		}
	}
}

void solve() {
	int n = nxt(), m = nxt();
	for (int i = 0; i < n; ++i) {
		a[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		gays[i].need = nxt();
	}
	for (int i = 1; i < n; ++i) {
		gays[i].gives = nxt();
	}
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	long long l = 0, r = n * 2e9;
	while (r > l + 1) {
		long long mid = (l + r) / 2;
		(check(mid, n) ? r : l) = mid;
	}
	cout << r << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}