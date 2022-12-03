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
vector<pair<int, int>> v[N];
void dfs(int x, int fa, map<int, int>& mc, int cur, int flag)
{
	if (x == flag)
		return;
	mc[cur] = 1;
	for (auto& [y, w] : v[x])
	{
		if (y == fa) continue;
		dfs(y, x, mc, cur ^ w, flag);
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
		int a, b;
		scanf("%d%d", &a, &b);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			v[x].emplace_back(y, w);
			v[y].emplace_back(x, w);
		}
		map<int, int> mc1;
		map<int, int> mc2;
		dfs(a, 0, mc1, 0, b);
		for (auto& [x, w] : v[b])
		{
			dfs(x, b, mc2, w, b);
		}
		int flag = 0;
		for (auto& p : mc1)
		{
			if (mc2.count(p.first))
				flag = 1;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}