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
const int MOD = INF;
const int N = 2e5 + 10;
const int M = 101;
int dp[N][M];
void init()
{
	for (int i = 0; i < M; i++) dp[i][i] = 1;
	for (int i = 0; i < N; i++) dp[i][0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < min(i, M); j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			if (dp[i][j] >= MOD)
				dp[i][j] -= MOD;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	init();
	cin >> ncase;
	while (ncase--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		sort(v.begin(), v.end());
		int ptr = 0;
		LL ans = 0;
		for (int i = 0; i < n; i++)
		{
			while (ptr < n && v[ptr] <= v[i] + k) ptr++;
			int tot = ptr - i - 1;
			ans += dp[tot][m - 1];
		}
		printf("%lld\n", ans % MOD);
	}
	return 0;
}