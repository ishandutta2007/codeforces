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
const int N = 1e5 + 10;
LL dp[N][2];
int a[N][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int o = 0; o < 2; o++)
	{
		for (int i = 1; i <= n; i++) cin >> a[i][o];
	}
	dp[1][0] = a[1][0];
	dp[1][1] = a[1][1];
	dp[2][0] = a[2][0] + dp[1][1];
	dp[2][1] = a[2][1] + dp[1][0];
	for (int i = 3; i <= n; i++)
	{
		for (int o = 0; o < 2; o++)
		{
			dp[i][o] = a[i][o] + max({ dp[i - 1][o ^ 1], dp[i - 2][0], dp[i - 2][1] });
		}
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
	return 0;
}