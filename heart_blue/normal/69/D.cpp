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
const int N = 1e3 + 10;
vector<pair<int, int>> vp;
map<tuple<int, int, int, int>, int> dp;
int d;
int dfs(int x, int y, int o1, int o2)
{
	if (x * x + y * y > d* d) return 1;
	auto p = make_tuple(x, y, o1, o2);
	if (dp.count(p)) return dp[p];
	int& ret = dp[p];
	if (o1 == 0)
	{
		if (dfs(y, x, o2, 1) == 0)
		{
			ret = 1;
			return ret;
		}
	}
	for (auto& p : vp)
	{
		int ox, oy;
		tie(ox, oy) = p;
		if (dfs(x + ox, y + oy, o1, o2) == 0)
		{
			ret = 1;
			break;
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x, y, n;
	cin >> x >> y >> n >> d;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vp.emplace_back(a, b);
	}
	if (dfs(x, y, 0, 0)) puts("Anton");
	else puts("Dasha");
	return 0;
}