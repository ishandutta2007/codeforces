#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

vector <int> from[200010];
int dp[200010];
int ans[200010];

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

void dfs(int x, int last) {
	dp[x] = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dfs(v, x);
		dp[x] = 1ll * dp[x] * (dp[v] + 1) % mod;
	}
}

void get_ans(int x, int last, long long up) {
	ans[x] = dp[x] * (up + 1) % mod;
	if (!from[x].size()) return ;
	vector <long long> suc(from[x].size());
	suc[(int)from[x].size() - 1] = 1;
	for (int i = (int)from[x].size() - 1; i >= 1; i--) {
		int v = from[x][i];
		suc[i - 1] = suc[i] * (dp[v] + 1) % mod;
	}
	long long pre = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		get_ans(v, x, 1ll * (up + 1) * pre % mod * suc[i] % mod);
		pre = pre * (dp[v] + 1) % mod;
	}
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int x; scanf("%d", &x);
		from[x].push_back(i);
	}
	dfs(1, 1), get_ans(1, 1, 0);
	ans[1] = dp[1];
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}