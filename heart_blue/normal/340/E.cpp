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
const int N = 2e3 + 10;
int a[N];
int vis[N];
LL dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x, y;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] != -1) vis[a[i]] = 1;
	}
	x = y = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == -1) y++;
		else if (vis[i] == 0) x++;
	}
	y -= x;
	dp[0] = 1;
	for (int i = 1; i <= x; i++) dp[0] = dp[0] * i % INF;
	for (int i = 1; i <= y; i++)
	{
		dp[i] = dp[i - 1] * x + dp[i - 1] * (i - 1);
		if (i > 1) dp[i] += dp[i - 2] * (i - 1);
		dp[i] %= INF;
	}
	cout << dp[y] << endl;
	return 0;
}