// Codeforces Beta Round #33
// Problem D -- Knights
#include <cstring>
#include <iostream>

#define N 1001

#define SQR(x) (x) * (x)

using namespace std;

int n, m, k, parent[N], inside[N], depth[N], dp[N][N];
long long kx[N], ky[N], r[N], cx[N], cy[N];

int getDepth(int x)
{
	if(depth[x] != -1)
		return depth[x];
	return depth[x] = getDepth(parent[x]) + 1;
}

int solve(int x, int y)
{
	if(dp[x][y] == -1)
	{
		if(depth[x] < depth[y])
			dp[x][y] = solve(x, parent[y]) + 1;
		else
			dp[x][y] = solve(parent[x], y) + 1;
	}
	return dp[x][y];
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++ i)
		cin >> kx[i] >> ky[i];
	for(int i = 1; i <= m; ++ i)
		cin >> r[i] >> cx[i] >> cy[i];
	r[0] = 2000000000LL, cx[0] = cy[0] = 0;
	for(int i = 1; i <= n; ++ i)
	{
		inside[i] = 0;
		for(int j = 1; j <= m; ++ j)
			if(SQR(kx[i] - cx[j]) + SQR(ky[i] - cy[j]) < SQR(r[j]) && r[j] < r[inside[i]])
				inside[i] = j;
	}
	for(int i = 1; i <= m; ++ i)
	{
		parent[i] = 0;
		for(int j = 1; j <= m; ++ j)
			if(SQR(cx[i] - cx[j]) + SQR(cy[i] - cy[j]) < SQR(r[i] - r[j]) && r[i] < r[j] && r[j] < r[parent[i]])
				parent[i] = j;
	}
	memset(depth, -1, sizeof(depth));
	depth[0] = 0;
	for(int i = 1; i <= m; ++ i)
		getDepth(i);		
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i <= m; ++ i)
		dp[i][i] = 0;
	for(int i = 1; i <= k; ++ i)
	{
		int a, b;
		cin >> a >> b;
		cout << solve(inside[a], inside[b]) << "\n";
	}
	return 0;
}