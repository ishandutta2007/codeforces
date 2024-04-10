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
const int N = 1e4 + 10;
int dp[N];
int maxv[N];
int a[N];
int lsum[N];
int rsum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (n--)
	{
		int k;
		cin >> k;
		a[0] = lsum[0] = rsum[0] = 0;
		for (int i = 1; i <= k; i++) cin >> a[i];
		for (int i = 1; i <= k; i++)
		{
			lsum[i] = a[i] + lsum[i - 1];
		}
		reverse(a + 1, a + k + 1);
		for (int i = 1; i <= k; i++)
		{
			rsum[i] = a[i] + rsum[i - 1];
		}
		MEM(maxv, 0);
		for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				maxv[i] = max(maxv[i], lsum[j] + rsum[i - j]);
			}
		}
		for (int i = m; i > 0; i--)
		{
			for (int j = min(i, k); j > 0; j--)
			{
				if (dp[i - j] || i - j == 0)
					dp[i] = max(dp[i - j] + maxv[j], dp[i]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= m; i++) ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}