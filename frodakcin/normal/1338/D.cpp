#include <cstdio>
#include <algorithm>
#include <vector>
 
const int MN = 1e5 + 100;
int N;
std::vector<int> a[MN];
int dp[MN][2];
 
int ans = 0;
int p[MN];
void dfs(int n = 1)
{
	dp[n][1] = 1, dp[n][0] = 0;
	int k[2] = {0, 0};
	int q[2] = {0, 0};
	int c = 0;
	for(int x : a[n])
		if(x != p[n])
		{
			++c;
			p[x] = n;
			dfs(x);
			for(int i = 0, v = std::max(dp[x][0], dp[x][1]);i < 2;++i)
				if(v > k[i])
					std::swap(v, k[i]);
			for(int i = 0, v = dp[x][0];i < 2;++i)
				if(v > q[i])
					std::swap(v, q[i]);
		}
	ans = std::max(ans, k[0] + k[1] + c - 2 + !!p[n]);
	ans = std::max(ans, q[0] + q[1] + 1);
	if(k[0] > 1) dp[n][0] = c - 1 + k[0];
	else dp[n][0] = c;
	dp[n][1] = q[0] + 1;
	ans = std::max(ans, dp[n][0]);
	ans = std::max(ans, dp[n][1]);
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 0, u, v;i < N-1;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	dfs();
	printf("%d\n", ans);
	return 0;
}