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
#include <cassert>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
pair<int, int> vp[N];
LL dp[N];
int pre[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		vp[i] = { x,i };
	}
	sort(vp + 1, vp + n + 1);
	MEM(dp, 0x3f);
	dp[0] = 0;
	for (int i = 3; i <= n; i++)
	{
		for (int j = 2; j <= 20; j++)
		{
			int r = i;
			int l = i - j;
			if (l <= 0) continue;
			if (dp[l - 1] + vp[r].first - vp[l].first < dp[r])
			{
				dp[r] = dp[l - 1] + vp[r].first - vp[l].first;
				pre[r] = l - 1;
			}
		}
	}
	int x = n;
	int cnt = 0;
	while (x)
	{
		cnt++;
		int p = pre[x];
		while (x > p) ans[vp[x--].second] = cnt;
	}
	printf("%lld %d\n", dp[n], cnt);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}