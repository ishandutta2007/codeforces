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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
LL dp[2][N];
int q[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, x;
	cin >> n >> k >> x;
	MEM(dp, 0);
	int o = 0;
	int head = 0, tail = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= k; i++) dp[o][i] = a[i];
	for (int j = 2; j <= x; j++)
	{
		head = tail = 0;
		q[tail++] = j - 1;
		o ^= 1;
		MEM(dp[o], 0);
		for (int i = j; i <= n; i++)
		{
			while (head < tail && q[head] + k < i) head++;
			if (head < tail) dp[o][i] = a[i] + dp[o ^ 1][q[head]];
			while (head < tail && dp[o ^ 1][q[tail - 1]] < dp[o ^ 1][i]) tail--;
			if (dp[o ^ 1][i]) q[tail++] = i;
		}
	}
	LL ans = 0;
	for (int i = 0; i < k; i++)
	{
		ans = max(ans, dp[o][n - i]);
	}
	if (ans == 0) ans = -1;
	cout << ans << '\n';
	return 0;
}