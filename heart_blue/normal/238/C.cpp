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
const int N = 5e3 + 10;
vector<pair<int, int>> vp[N];
int tot = 0;
int key = INF;
void dfs(int x, int fa = 0, int sum = 0, int minv = 0)
{
	minv = min(minv, sum);
	key = min(key, minv - sum);
	for (auto [y, o] : vp[x])
	{
		if (y == fa) continue;
		tot += o;
		dfs(y, x, sum + o, minv + (o ^ 1));
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
		vp[x].emplace_back(y, 0);
		vp[y].emplace_back(x, 1);
	}
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		tot = 0;
		key = INF;
		dfs(i);
		ans = min(ans, tot + key);
	}
	printf("%d\n", ans);
	return 0;
}