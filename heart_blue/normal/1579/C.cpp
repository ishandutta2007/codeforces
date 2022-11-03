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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e1 + 10;
char str[N][N];
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
		}
		MEM(flag, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (str[i][j] == '.') continue;
				if (j - k < 0) continue;
				if (j + k >= m) continue;
				if (i - k < 0) continue;
				int ok = 1;
				for (int t = 1; t <= k; t++)
				{
					if (str[i - t][j - t] == '*' && str[i - t][j + t] == '*') continue;
					else ok = 0;
				}
				if (ok == 0) continue;
				for (int t = 0; i - t >= 0 && j - t >= 0 && j + t < m; t++)
				{
					if (str[i - t][j - t] == '*' && str[i - t][j + t] == '*')
					{
						flag[i - t][j - t] = 1;
						flag[i - t][j + t] = 1;
					}
					else
					{
						break;
					}
				}
			}
		}
		int ok = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (str[i][j] == '*' && flag[i][j] == 0)
					ok = 0;
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}