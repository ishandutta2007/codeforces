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
const int N = 3e2 + 10;
vector<pair<int, int>> vp[3][2];
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				vp[i][j].clear();
			}
		}
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str[i] + 1);
			for (int j = 1; j <= n; j++)
			{
				if (str[i][j] == '.') continue;
				vp[(i + j) % 3][str[i][j] == 'O'].emplace_back(i, j);
				tot++;
			}
		}
		int k = tot / 3;
		int ok = 0;
		for (int i = 0; i < 3; i++)
		{
			if (ok) break;
			for (int j = 0; j < 3; j++)
			{
				if (i == j) continue;
				if (vp[i][0].size() + vp[j][1].size() <= k)
				{
					for (auto [x, y] : vp[i][0])
						str[x][y] = 'O';
					for (auto [x, y] : vp[j][1])
						str[x][y] = 'X';
					ok = 1;
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			puts(str[i] + 1);
	}
	return 0;
}