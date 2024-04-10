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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int a[N];
int b[N];
LL dp[2][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] -= i;
	}
	memcpy(b, a, sizeof(a));
	sort(b + 1, b + n + 1);
	int o = 0;
	for (int i = 1; i <= n; i++)
	{
		o ^= 1;
		LL minv = INF * INF;
		for (int j = 1; j <= n; j++)
		{
			minv = min(minv, dp[o ^ 1][j]);
			dp[o][j] = minv + abs(a[i] - b[j]);
		}
	}
	LL ans = INF * INF;
	for (int i = 1; i <= n; i++) ans = min(ans, dp[o][i]);
	printf("%lld\n", ans);
	return 0;
}