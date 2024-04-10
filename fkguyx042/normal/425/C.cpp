#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, s, e;
const int N = 100005;
int a[N], b[N];

vector<int> bucket[N];

int dp[N][3 * 100000 / 1000 + 1];
const int INF = 1000000000;

int getnext(int pos, int val) {
	int t = lower_bound(bucket[val].begin(), bucket[val].end(), pos) - bucket[val].begin();
	return t == bucket[val].size() ? INF : bucket[val][t] + 1;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &e);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", b + i);
		bucket[b[i]].push_back(i);
	}
	int cap = s / e;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= cap; ++j) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < cap; ++j) {
			if (dp[i][j] < m) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], getnext(dp[i][j], a[i]));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= cap; ++j) {
			if (dp[i][j] == INF) {
				continue;
			}
			if (dp[i][j] + i + j * e <= s) {
				ans = max(ans, j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}