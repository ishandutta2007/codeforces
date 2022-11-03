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
const int N = 4e5 + 10;
const int M = 60 + 10;
LL dp[M][6];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 6; i++) dp[1][i] = 1;
	for (int o = 2; o <= 60; o++)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if ((i ^ j) <= 1) continue;
				for (int k = 0; k < 6; k++)
				{
					if ((i ^ k) <= 1) continue;
					dp[o][i] = (dp[o][i] + dp[o - 1][j] * dp[o - 1][k]) % INF;
				}
			}
		}
	}
	int k;
	cin >> k;
	LL ans = 0;
	for (int i = 0; i < 6; i++)
		ans += dp[k][i];
	printf("%lld\n", ans % INF);
	return 0;
}