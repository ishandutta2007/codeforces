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
const int N = 1e3 + 10;
int flag[N][N];
vector<tuple<int, int, int>> ans;
void dfs(int l, int r)
{
	if (l == r)
	{
		ans.emplace_back(l, r, r);
		return;
	}
	if (flag[l][r - 1])
	{
		ans.emplace_back(l, r, r);
		dfs(l, r - 1);
	}
	else if (flag[l + 1][r])
	{
		ans.emplace_back(l, r, l);
		dfs(l + 1, r);
	}
	else
	{
		for (int i = l + 1; i < r; i++)
		{
			if (flag[l][i - 1] && flag[i + 1][r])
			{
				ans.emplace_back(l, r, i);
				dfs(l, i - 1);
				dfs(i + 1, r);
				break;
			}
		}
	}
}
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
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				flag[i][j] = 0;
			}
		}
		ans.clear();
		for (int i = 1; i <= n; i++)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			flag[l][r] = 1;
		}
		dfs(1, n);
		for (auto& [l, r, d] : ans)
			printf("%d %d %d\n", l, r, d);
	}
	return 0;
}