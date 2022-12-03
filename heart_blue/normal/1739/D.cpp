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
int fa[N];
int depth[N];
int vis[N];
void dfs(int x, int p = 0)
{
	depth[x] = depth[p] + 1;
	for (auto& y : v[x])
	{
		dfs(y, x);
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
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 2; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			fa[i] = x;
			v[x].push_back(i);
		}
		depth[0] = -1;
		dfs(1);
		int l = 1, r = n;
		int ans = n - 1;
		vector<pair<int, int>> vp;
		for (int i = 1; i <= n; i++)
			vp.emplace_back(depth[i], i);
		sort(vp.rbegin(), vp.rend());
		while (l <= r)
		{
			int mid = (l + r) / 2;
			fill(vis, vis + n + 1, 0);
			int tot = 0;
			for (auto [d, x] : vp)
			{
				if (d <= mid) break;
				int flag = 0;
				for (int i = 1; i <= mid; i++)
				{
					if (vis[x])
					{
						flag = 1;
						break;
					}
					vis[x] = 1;
					if (i < mid) x = fa[x];
				}
				if (flag) continue;
				tot++;
				vis[x] = 1;
			}
			if (tot <= k) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}