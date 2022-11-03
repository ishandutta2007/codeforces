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
const int N = 5e2 + 10;
int dp[2][N];
int cost[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	MEM(dp, 0);
	int o = 0;
	while (n--)
	{
		o ^= 1;
		MEM(dp[o], 0x3f);
		string str;
		cin >> str;
		int tot = 0;
		for (auto &c : str) tot += c - '0';
		MEM(cost, 0x3f);
		for (int i = 0; i < m; i++)
		{
			if (str[i] == '0') continue;
			int cnt = 0;
			for (int j = i; j < m; j++)
			{
				if (str[j] == '0') continue;
				cnt += str[j] - '0';
				cost[tot - cnt] = min(cost[tot - cnt], j - i + 1);
			}
		}
		cost[tot] = 0;
		for (int i = k; i >= 0; i--)
		{
			for (int j = min(tot, i); j >= 0; j--)
			{
				dp[o][i] = min(dp[o][i], dp[o ^ 1][i - j] + cost[j]);
			}
		}
	}
	cout << dp[o][k] << endl;
	return 0;
}