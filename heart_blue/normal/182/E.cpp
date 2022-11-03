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
const int N = 3e3 + 10;
int dp[N][110][2];
int a[110][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0] >> a[i][1];
		int& x = a[i][0], & y = a[i][1];
		if (x > y) swap(x, y);
		dp[x][i][0]++;
		if (x != y) dp[y][i][1]++;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int o = 0; o < 2; o++)
			{
				int x = a[j][o ^ 1];
				if (i + x > m) continue;
				for (int k = 1; k <= n; k++)
				{
					if (k == j) continue;
					int maxo = a[k][0] == a[k][1];
					maxo = 2 - maxo;
					for (int o2 = 0; o2 < maxo; o2++)
					{
						if (a[k][o2] != x) continue;
						int& tmp = dp[i + x][k][o2] += dp[i][j][o];
						if (tmp >= INF)
							tmp -= INF;
					}
				}
			}
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
		ans += dp[m][i][0] + dp[m][i][1];
	printf("%lld\n", ans % INF);
	return 0;
}