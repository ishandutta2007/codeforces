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
const int N = 3e5 + 10;
vector<int> v[N];
int sons[N];
int fa[N];
void dfs(int x, int p = 0)
{
	fa[x] = p;
	sons[x] = 1;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
		sons[x] += sons[y];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(x);
	int py = y;
	while (fa[py] != x) py = fa[py];
	LL ans = 1LL * n*(n - 1);
	ans -= 1LL * (sons[x] - sons[py])*sons[y];
	printf("%lld\n", ans);
	return 0;
}