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
const int N = 5e5 + 10;
vector<pair<int, int>> vp[N];
int n, k;
pair<LL, LL> dfs(int x, int fa = 0)
{
	LL ret0 = 0, ret1 = 0;
	LL tot = 0;
	vector<LL> key;
	for (auto [y, w] : vp[x])
	{
		if (y == fa) continue;
		auto [a, b] = dfs(y, x);
		a += w;
		a = max(a, b);
		tot += a;
		key.push_back(a - b);
	}
	sort(key.rbegin(), key.rend());
	while (key.size() > k) tot -= key.back(), key.pop_back();
	ret1 = tot;
	while (key.size() > k - 1) tot -= key.back(), key.pop_back();
	ret0 = tot;
	return { ret0,ret1 };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			vp[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y, w;;
			scanf("%d%d%d", &x, &y, &w);
			vp[x].emplace_back(y, w);
			vp[y].emplace_back(x, w);
		}
		auto [res1, res2] = dfs(1);
		printf("%lld\n", max(res1, res2));
	}
	return 0;

}