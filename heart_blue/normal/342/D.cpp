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
#include <regex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e4 + 10;
LL dp[N][8][2];
char str[3][N];
int cnt[] = { 0,1,1,2,1,2,2,3 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s%s%s", str[0] + 1, str[1] + 1, str[2] + 1);
	str[0][n + 1] = str[1][n + 1] = str[2][n + 1] = '.';
	dp[0][7][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (dp[i][j][k] == 0) continue;
				//cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
				int kk = k;
				int o = j ^ 7;
				int s = 0;
				int flag = 0;
				for (int t = 0; t < 3; t++)
				{
					if (o >> t & 1)
					{
						if (str[t][i + 2] == 'O') kk = 1;
						if (i >= 1 && str[t][i - 1] == 'O') kk = 1;
					}
					if (str[t][i + 1] != '.')
						s |= 1 << t;
					if (str[t][i + 1] == 'O')
						flag = 1;
				}
				if (o & s) continue;
				int rest = (o | s) ^ 7;
				int r = rest;
				while (1)
				{
					if (r == 3 || r == 6)
					{
						LL& tmp = dp[i + 1][o | s | r][flag | kk] += dp[i][j][k];
						if (tmp >= INF) tmp -= INF;
					}
					if (r == 0) break;
					r = (r - 1) & rest;
				}
				LL tmp = dp[i + 1][o | s][kk] += dp[i][j][k];
				if (tmp >= INF)
					tmp -= INF;
			}
		}
	}
	printf("%lld\n", dp[n + 1][0][1]);
	return 0;
}