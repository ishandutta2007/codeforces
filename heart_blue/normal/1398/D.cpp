#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int dp[N][N][N];
int a[3][N];
int dfs(int x, int y, int z)
{
	if (dp[x][y][z] != -1) return dp[x][y][z];
	int& ret = dp[x][y][z] = 0;
	int sz[3] = { x,y,z };
	for (int o = 0; o < 3; o++)
	{
		int flag = 1;
		vector<int> v;
		for (int i = 0; i < 3; i++)
		{
			if (i == o) continue;
			v.push_back(a[i][sz[i]--]);
			if (sz[i] < 0) flag = 0;
		}
		if (flag)
		{
			ret = max(ret, v[0] * v[1] + dfs(sz[0], sz[1], sz[2]));
		}
		for (int i = 0; i < 3; i++)
		{
			if (i == o) continue;
			sz[i]++;
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int sz[3] = { n,m,k };
	for (int o = 0; o < 3; o++)
	{
		for (int i = 1; i <= sz[o]; i++)
			scanf("%d", &a[o][i]);
		sort(a[o] + 1, a[o] + sz[o] + 1);
	}
	MEM(dp, -1);
	printf("%d\n", dfs(n, m, k));
	return 0;
}