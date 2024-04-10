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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		map<int, int> mc;
		mc[0] = 0;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = INF;
			int x;
			scanf("%d", &x);
			sum ^= x;
			if (mc.count(sum))
				dp[i] = (i - mc[sum] - 1) + dp[mc[sum]];
			dp[i] = min(dp[i - 1] + (x != 0), dp[i]);
			mc[sum] = i;
		}
		printf("%d\n", dp[n]);

	}
	return 0;
}