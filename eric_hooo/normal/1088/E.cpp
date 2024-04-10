#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int n;
int a[300010];
long long dp[300010];
vector <int> from[300010];
long long maxj = -INF;
int cnt = 0;

void dfs(int x, int last){
	dp[x] = a[x];
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		dfs(v, x), dp[x] += max(dp[v], 0ll);
	}
	if (maxj < dp[x]) maxj = dp[x];
}

void dfs2(int x, int last){
	dp[x] = a[x];
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		dfs2(v, x), dp[x] += max(dp[v], 0ll);
	}
	if (maxj == dp[x]) dp[x] = -INF, cnt++;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++){
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	dfs(1, 1), dfs2(1, 1);
	printf("%I64d %d\n", maxj * cnt, cnt);
	return 0;
}