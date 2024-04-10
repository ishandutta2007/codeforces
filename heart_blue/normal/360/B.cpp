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
const int N = 2e3 + 10;
LL a[N];
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	LL l = 0, r = 2e9;
	LL ret = r;
	while (l <= r)
	{
		LL mid = (l + r) >> 1;
		dp[1] = 0;
		int tot = n;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = i - 1;
			for (int j = 1; j < i; j++)
			{
				if (abs(a[i] - a[j]) <= (i - j)*mid)
					dp[i] = min(dp[i], dp[j] + i - j - 1);
			}
			tot = min(tot, dp[i] + n - i);
		}
		if (tot <= k) ret = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ret << endl;
	return 0;
}