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
const int N = 3e5 + 10;
int dp[N];
int maxv[N];
pair<int, int> vp[N];
int t[N];
inline int dis(int i, int j)
{
	return abs(vp[i].first - vp[j].first) + abs(vp[i].second - vp[j].second);
}
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	vp[0] = make_pair(1, 1);
	t[0] = 0;
	MEM(dp, 0xdf);
	MEM(maxv, 0xdf);
	dp[0] = 0;
	maxv[0] = 0;
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d%d", &t[i], &vp[i].first, &vp[i].second);
		for (int j = i - 1; j >= 0; j--)
		{
			if (t[i] - t[j] >= 2 * n)
			{
				dp[i] = max(dp[i], maxv[j] + 1);
				break;
			}
			if (t[i] - t[j] >= dis(i, j))
				dp[i] = max(dp[i], dp[j] + 1);
		}
		maxv[i] = max(dp[i], maxv[i - 1]);
	}
	printf("%d\n", maxv[q]);
	return 0;
}