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
const int N = 2e5 + 10;
vector<pair<int, int>> vp[N];
vector<int> ans[N];
int maxv = 0;
void dfs(int x, int fa = 0, int c = 0)
{
	int cur = 0;
	for (auto& p : vp[x])
	{
		int y, id;
		tie(y, id) = p;
		if (y == fa) continue;
		cur++;
		if (cur == c) cur++;
		ans[cur].push_back(id);
		dfs(y, x, cur);
	}
	maxv = max(maxv, cur);
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
		vp[x].emplace_back(y, i);
		vp[y].emplace_back(x, i);
	}
	dfs(1);
	printf("%d\n", maxv);
	for (int i = 1; i <= maxv; i++)
	{
		printf("%d", ans[i].size());
		for (auto& x : ans[i])
			printf(" %d", x);
		puts("");
	}
	return 0;
}