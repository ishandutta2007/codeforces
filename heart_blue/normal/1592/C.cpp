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
const int N = 1e5 + 10;
int a[N];
vector<int> v[N];
int ans = 0;
int dfs(int x, int key, int fa = 0)
{
	int tot = a[x];
	int cnt = 0;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		cnt += dfs(y, key, x);
		tot ^= a[y];
	}
	a[x] = tot;
	if (cnt >= 2) ans = 1;
	if (cnt == 1 && tot == 0) ans = 1;
	if (tot == key)
		return 1;
	else
		return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		k--;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum ^= a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			v[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if (sum == 0)
		{
			puts("YES");
			continue;
		}
		if (k == 1)
		{
			puts("NO");
			continue;
		}
		ans = 0;
		dfs(1, sum);
		if (ans) puts("YES");
		else puts("NO");

	}
	return 0;
}