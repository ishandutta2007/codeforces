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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int dis[N][N];
char str[N][N];
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	MEM(str, 0);
	for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
	MEM(dis, 0x3f);
	dis[1][1] = str[1][1] != 'a';
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dis[i + 1][j] = min(dis[i + 1][j], dis[i][j] + (str[i + 1][j] != 'a'));
			dis[i][j + 1] = min(dis[i][j + 1], dis[i][j] + (str[i][j + 1] != 'a'));
		}
	}
	int maxv = 2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dis[i][j] <= k)
			{
				maxv = max(maxv, i + j);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dis[i][j] <= k && i + j == maxv)
			{
				flag[i][j] = 1;
			}
		}
	}
	string ans;
	if (maxv == 2 && flag[1][1] == 0) ans.push_back(str[1][1]), flag[1][1] = 1;
	for (int i = maxv; i < 2 * n; i++)
	{
		char c = 'z';
		for (int j = 1; j <= n; j++)
		{
			if (i - j < 1 || i - j > n) continue;
			int x = j, y = i - j;
			if (flag[x][y] == 0) continue;
			if (y + 1 <= n)
			{
				c = min(c, str[x][y + 1]);
			}
			if (x + 1 <= n)
			{
				c = min(c, str[x + 1][y]);
			}
		}
		ans.push_back(c);
		for (int j = 1; j <= n; j++)
		{
			if (i - j < 1 || i - j > n) continue;
			int x = j, y = i - j;
			if (flag[x][y] == 0) continue;
			if (y + 1 <= n)
			{
				flag[x][y + 1] = c == str[x][y + 1];
			}
			if (x + 1 <= n)
			{
				flag[x + 1][y] = c == str[x + 1][y];
			}
		}
	}
	ans = string(2 * n - 1- ans.length(), 'a') + ans;
	puts(ans.c_str());
	return 0;
}