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
const int N = 1e2 + 10;
int dp[N][N];
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x = 1, y = 1;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	int ans = 0;
	while (x <=n && y <= m)
	{
		if (str[x][y] == '*')
			ans++;
		int a = INF;
		int b = INF;
		for (int i = x + 1; i <= n; i++)
		{
			if (str[i][y] == '*')
			{
				a = i - x;
				break;
			}
		}
		for (int i = y + 1; i <= m; i++)
		{
			if (str[x][i] == '*')
			{
				b = i - y;
				break;
			}
		}
		if (b <= a) y++;
		else x++;
	}
	printf("%d\n", ans);
	return 0;
}