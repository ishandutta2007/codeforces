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
vector<tuple<int, int, int>> vp[N];
vector<LL> v1, v2;
LL ans[N];
void dfs(int x)
{
	ans[x] = upper_bound(v2.begin(), v2.end(), v1.back()) - 1 - v2.begin();
	for (auto& [y, a, b] : vp[x])
	{
		v1.push_back(a + v1.back());
		v2.push_back(b + v2.back());
		dfs(y);
		v1.pop_back();
		v2.pop_back();
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
			vp[i].clear();
		v1.clear();
		v2.clear();
		v1.push_back(0);
		v2.push_back(0);
		for (int i = 2; i <= n; i++)
		{
			int p, a, b;
			scanf("%d%d%d", &p, &a, &b);
			vp[p].emplace_back(i, a, b);
		}
		dfs(1);
		for (int i = 2; i <= n; i++)
			printf("%lld%c", ans[i], " \n"[i == n]);
	}
	return 0;
}