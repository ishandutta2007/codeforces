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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		MEM(dp, 0);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			for (int j = i - 1; j >= 0; j--)
			{
				if (j == i - x)
					dp[j]++;
				if (j == 0) break;
				dp[j] = max(dp[j], dp[j - 1]);
			}
		}
		int ans = INF;
		for (int i = 0; i <= n; i++)
		{
			if (dp[i] >= k)
				ans = min(ans, i);
		}
		if (ans == INF) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}