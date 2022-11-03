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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, k;
	cin >> t >> k;
	dp[0] = 0;
	for (int i = 1; i < N; i++)
	{
		if (i < k) dp[i] = 1;
		else if (i == k) dp[k] = 2;
		else dp[i] = dp[i - 1] + dp[i - k];
		if (dp[i] >= INF) dp[i] -= INF;
	}
	for (int i = 1; i < N; i++)
	{
		dp[i] += dp[i - 1];
		if (dp[i] >= INF) dp[i] -= INF;
	}
	while (t--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = dp[r] - dp[l - 1];
		if (ans < 0) ans += INF;
		printf("%d\n", ans);
	}
	return 0;
}