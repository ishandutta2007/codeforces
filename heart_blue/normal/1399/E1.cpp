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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<pair<int, int>> v[N];
int sz[N];
int fa[N];
void dfs(int x, int p = 0)
{
	fa[x] = p;
	sz[x] = 0;
	int cnt = 0;
	for (auto& [y, w] : v[x])
	{
		if (y == p)
			continue;
		cnt++;
		dfs(y, x);
		sz[x] += sz[y];
	}
	if (cnt == 0)
		sz[x] = 1;
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
		LL s;
		scanf("%d%lld", &n, &s);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			v[x].emplace_back(y, w);
			v[y].emplace_back(x, w);
		}
		dfs(1);
		vector<LL> vp;
		LL sum = 0;
		for (int i = 1; i <= n; i++)
		{
			for (auto [j, w] : v[i])
			{
				if (fa[j] == i)
				{
					LL tot = sz[j];
					sum += tot * w;
					while (w)
					{
						vp.push_back((w - w / 2) * tot);
						w /= 2;
					}
				}
			}
		}
		sort(vp.begin(), vp.end());
		int ans = 0;
		while (sum > s)
		{
			ans++;
			sum -= vp.back();
			vp.pop_back();
		}
		printf("%d\n", ans);
	}
	return 0;
}