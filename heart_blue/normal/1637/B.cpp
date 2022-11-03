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
#include <iterator>
#include <complex>
#include <valarray>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int dp[N];
int a[N];
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
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			MEM(dp, 0);
			for (int j = i; j <= n; j++)
			{
				map<int, int> mc;
				int cur = 0;
				for (int k = j; k >= i; k--)
				{
					mc[a[k]]++;
					while (mc.count(cur)) cur++;
					dp[j] = max(dp[j], dp[k - 1] + 1 + cur);
				}
				ans += dp[j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}