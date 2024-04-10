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
const int N = 2e5 + 10;
double dp[2][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<double> key;
	int o = 0;
	key.push_back(0);
	int cur = 0;
	int k, q;
	cin >> k >> q;
	dp[o][0] = 2000;
	while (dp[o][k] < 1001)
	{
		cur++;
		o ^= 1;
		for (int i = 1; i <= k; i++)
		{
			dp[o][i] = dp[o ^ 1][i] * i / k + dp[o ^ 1][i - 1] * (k - i + 1) / k;
		}
		dp[o][0] = 0;
		key.push_back(dp[o][k]);
	}
	while (q--)
	{
		double x;
		cin >> x;
		printf("%d\n", lower_bound(key.begin(), key.end(), x) - key.begin());
	}
	return 0;
}