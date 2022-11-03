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
const int N = 1e5 + 10;
int a[N];
int dp[2][N];
int maxv[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, p;
	cin >> n >> k >> p;
	int o = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] %= p;
		sum[i] = sum[i - 1] + a[i];
		dp[o][i] = (a[i] + dp[o][i - 1]) % p;
	}
	for (int i = 2; i <= k; i++)
	{
		o ^= 1;
		MEM(maxv, -INF);
		maxv[0] = sum[i - 1];
		int tot = 0;
		for (int j = i; j <= n; j++)
		{
			for (int s = 0; s < p; s++)
			{
				dp[o][j] = max(dp[o][j], maxv[s] + (s + tot + a[j]) % p);
			}
			tot = (tot + a[j]) % p;
			maxv[(p - tot) % p] = max(maxv[(p - tot) % p], dp[o ^ 1][j]);
		}
	}
	cout << dp[o][n] << endl;
	return 0;
}