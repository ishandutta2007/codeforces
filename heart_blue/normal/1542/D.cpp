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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
const int MOD = 998244353;
LL dp[2][N][2];
inline void add(LL& x, int y)
{
	x += y;
	while (x >= MOD) x -= MOD;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		string op;
		int x;
		cin >> op;
		if (op == "-") vp.emplace_back(-1, -1);
		else
		{
			cin >> x;
			vp.emplace_back(x, i);
		}
	}
	LL ans = 0;
	for (int _ = 0; _ < vp.size(); _++)
	{
		if (vp[_].first == -1) continue;
		auto key = vp[_];
		MEM(dp, 0);
		dp[0][0][0] = 1;
		int o = 0;
		for (int i = 0; i < vp.size(); i++)
		{
			o ^= 1;
			MEM(dp[o], 0);
			if (vp[i].first == -1)
			{
				for (int i = n; i >= 1; i--)
				{
					for (int t = 0; t < 2; t++)
					{
						add(dp[o][i - 1][t], dp[o ^ 1][i][t]);
						add(dp[o][i][t], dp[o ^ 1][i][t]);
					}
				}
				add(dp[o][0][0], 2 * dp[o ^ 1][0][0]);
				add(dp[o][0][1], dp[o ^ 1][0][1]);
				continue;
			}
			if (vp[i] > key)
			{
				for (int i = n; i >= 0; i--)
				{
					for (int t = 0; t < 2; t++)
					{
						add(dp[o][i][t], 2 * dp[o ^ 1][i][t]);
					}
				}
				continue;
			}
			if (vp[i] < key)
			{
				for (int i = n; i >= 0; i--)
				{
					for (int t = 0; t < 2; t++)
					{
						add(dp[o][i + 1][t], dp[o ^ 1][i][t]);
						add(dp[o][i][t], dp[o ^ 1][i][t]);
					}
				}
				continue;
			}
			for (int i = n; i >= 0; i--)
			{
				add(dp[o][i][1], dp[o ^ 1][i][0]);
			}
		}
		LL sum = 0;
		for (int i = 0; i <= n; i++)
		{
			sum += dp[o][i][1];
		}
		sum %= MOD;
		ans += sum * key.first % MOD;
	}
	cout << ans % MOD << endl;
	return 0;
}