#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5010, INF = 1000000000;

int n, k, v;
int a[N];
bool dp[N][N], take[N][N];
vector<pair<int, pair<int, int> > > ans;

int norm(int x) { return x >= k ? x - k : x; }

void perf(int cnt, int x, int y) {
	int res = min((ll)a[x], cnt * (ll)k);
	a[x] -= res;
	a[y] += res;
	ans.push_back(make_pair(cnt, make_pair(x, y)));
}

int main() {
	scanf("%d%d%d", &n, &k, &v);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	dp[0][0] = true;
	int r = v % k;
	for (int i = 1; i <= n; ++i) {
		int rr = a[i] % k;
		for (int j = 0; j < k; ++j) {
			if (dp[i - 1][j]) {
				dp[i][j] = true;
			} else if (dp[i - 1][norm(j + k - rr)]) {
				dp[i][j] = true;
				take[i][j] = true;
			}
		}
	}
	if (!dp[n][r]) {
		puts("NO");
		return 0;
	}
	int result = -1;
	if (r == 0)
		result = 1;
	int gar = -1;
	for (int i = n; i; --i) {
		int rr = a[i] % k;
		if (take[i][r]) {
			r = norm(r + k - rr);
			if (result == -1)
				result = i;
			else
				perf(INF, i, result);
		} else if (gar == -1)
			gar = i;
		else
			perf(INF, i, gar);
	}
	if (gar != -1 && a[gar] >= k)
		perf(a[gar] / k, gar, result);

	if (a[result] < v)
		puts("NO");
	else {
		if (a[result] > v)
			perf((a[result] - v) / k, result, result == 1 ? 2 : 1);
		puts("YES");
		for (int i = 0; i < ans.size(); ++i)
			printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
	}
	return 0;
}