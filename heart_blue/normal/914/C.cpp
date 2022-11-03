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
const int N = 1e3 + 10;
int cnt[N];
int step[N];
int dp[N][N];
void init()
{
	cnt[0] = 0;
	for (int i = 1; i < N; i++) cnt[i] = (i & 1) + cnt[i >> 1];
	step[1] = 1;
	for (int i = 2; i < N; i++)
	{
		step[i] = 1 + step[cnt[i]];
	}
	for (int i = 0; i < N; i++) dp[i][0] = dp[i][i] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			if (dp[i][j] >= INF) dp[i][j] -= INF;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int k;
	cin >> k;
	int o = 0;
	int n = str.length();
	LL ans = 0;
	init();
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '1')
		{
			int rest = n - i - 1;
			for (int j = 0; j <= rest; j++)
			{
				if (step[o + j] == k)
				{
					ans += dp[rest][j];
					if (ans >= INF) ans -= INF;
				}
			}
			o++;
		}
	}
	if (step[o] == k) ans++;
	if (k == 1) ans--;
	if (ans >= INF) ans -= INF;
	if (ans < 0) ans += INF;
	cout << ans << endl;
	return 0;
}