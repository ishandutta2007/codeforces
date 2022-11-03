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
const int N = 1e2 + 10;
LL dp[N][N];
void init()
{
	MEM(dp, 0);
	for (int i = 0; i < N; i++) dp[i][0] = dp[i][i] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
}
LL getans(LL x, int k)
{
	int cnt = 0;
	LL ret = 0;
	for (int i = 63; i >= 0; i--)
	{
		if (x >> i & 1)
		{
			if (k >= cnt) ret += dp[i][k - cnt];
			cnt++;
		}
	}
	if (cnt == k) ret++;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL m, k;
	init();
	cin >> m >> k;
	LL l = 1, r = 1e18;
	LL n = 0;
	while (l <= r)
	{
		LL mid = (l + r) >> 1;
		LL tot = getans(2 * mid, k) - getans(mid, k);
		if (tot >= m) n = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << n << endl;
	return 0;
}