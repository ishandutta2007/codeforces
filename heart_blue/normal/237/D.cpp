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
const int N = 3e5 + 10;
vector<int> v[N];
int cnt = 0;
map<pair<int, int>, int> mc;
vector<pair<int, int>> ans;
void dfs(int x, int fa = 0)
{
	int pre = 0;
	if (mc.count(make_pair(fa, x)))
		pre = mc[{fa, x}];
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		int cur = mc[{x, y}] = ++cnt;
		printf("2 %d %d\n", x, y);
		if (pre) ans.emplace_back(pre, cur);
		pre = cur;
		dfs(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	printf("%d\n", n - 1);
	dfs(1);
	for (auto [l, r] : ans)
	{
		printf("%d %d\n", l, r);
	}
	return 0;
}