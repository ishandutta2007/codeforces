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
int cnt[3];
int dp[N][3];
void check(int n, int o = 1)
{
	cnt[0] += n / 3 * o;
	cnt[1] += n / 3 * o;
	cnt[2] += n / 3 * o;
	for (int i = 1; i <= n % 3; i++)
	{
		cnt[i] += o;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, l, r;
	cin >> n >> l >> r;
	check(r);
	check(l - 1, -1);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int& t = dp[i][(j + k) % 3] += 1LL * dp[i - 1][j] * cnt[k] % INF;
				if (t >= INF) t -= INF;
			}
		}
	}
	cout << dp[n][0];
	return 0;
}