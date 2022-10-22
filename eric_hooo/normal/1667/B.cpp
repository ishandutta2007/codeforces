#include <bits/stdc++.h>
using namespace std;

struct BIT {
	int T[500010];
	void init(int n) {
		for (int i = 0; i <= n; i++) {
			T[i] = -0x3f3f3f3f;
		}
	}
	void modify(int x, int v) {
		while (x <= 500010) T[x] = max(T[x], v), x += x & -x;
	}
	int query(int x) {
		int res = -0x3f3f3f3f;
		while (x) res = max(res, T[x]), x -= x & -x;
		return res;
	}
}pre, suc;

int a[500010];
long long S[500010];
int dp[500010];
int mem[500010];
vector <long long> all;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			S[i] = S[i - 1] + a[i];
		}
		all.clear();
		for (int i = 0; i <= n; i++) {
			all.push_back(S[i]);
		}
		sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
		int N = all.size();
		pre.init(N), suc.init(N);
		for (int i = 1; i <= N; i++) {
			mem[i] = -0x3f3f3f3f;
		}
		for (int i = 0; i <= n; i++) {
			int id = lower_bound(all.begin(), all.end(), S[i]) - all.begin() + 1;
			if (!i) dp[i] = 0;
			else dp[i] = max(mem[id], max(pre.query(id - 1) + i, suc.query(N - id) - i));
			pre.modify(id, dp[i] - i), suc.modify(N - id + 1, dp[i] + i);
			mem[id] = max(mem[id], dp[i]);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}