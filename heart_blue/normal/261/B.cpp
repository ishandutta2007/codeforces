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
const int N = 51;
int a[N];
double dp[N][N][N];
double ans = 0;
void solve(int n, int p)
{
	MEM(dp, 0);
	dp[0][0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k <= p; k++)
			{
				dp[i][j][k] += dp[i - 1][j][k];
				if (k + a[i] > p) continue;
				dp[i][j + 1][k + a[i]] += (j + 1) * dp[i - 1][j][k] / (n - j);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = p - a[n] + 1; j <= p; j++)
		{
			ans += i * dp[n - 1][i][j] / (n - i);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int p;
	cin >> p;
	if (sum <= p)
	{
		printf("%d\n", n);
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		swap(a[i], a[n]);
		solve(n, p);
		swap(a[i], a[n]);
	}
	printf("%.15f\n", ans);
	return 0;
}