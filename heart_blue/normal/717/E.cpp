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
const int N = 2e5 + 10;
vector<int> v[N];
vector<int> ans;
int c[N];
void dfs(int x, int fa = 0)
{
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		ans.push_back(x);
		c[x] = -c[x];
		dfs(y, x);
	}
	c[x] = -c[x];
	ans.push_back(x);
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		if (c[y] == 1) continue;
		ans.push_back(y);
		ans.push_back(x);
		c[x] = -c[x];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	c[1] = -c[1];
	if (c[1] == -1)
	{
		ans.push_back(v[1].back());
		ans.push_back(1);
		ans.push_back(v[1].back());
	}
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}