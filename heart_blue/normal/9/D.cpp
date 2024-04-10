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
const int N = 50;
LL dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	dp[1][1] = 1;
	dp[0][0] = 1;
	int n = 35, h = 35;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int h1 = 0; h1 <= j; h1++)
			{
				for (int h2 = 0; h2 <= i - j - 1; h2++)
				{
					dp[i][max(h1, h2) + 1] += dp[j][h1] * dp[i - j - 1][h2];
				}
			}
		}
	}
	cin >> n >> h;
	LL ans = 0;
	for (int i = h; i <= n; i++) ans += dp[n][i];
	cout << ans << endl;
	return 0;
}