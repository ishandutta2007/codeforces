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
		vector<tuple<int, int, int, int>> vp;
		for (int i = 1; i < n; i++)
		{
			int x, y, w, c;
			scanf("%d%d%d%d", &x, &y, &w, &c);
			v[x].emplace_back(y, w);
			v[y].emplace_back(x, w);
			vp.emplace_back(x, y, w, c);
		}
		dfs(1);
		vector<LL> vp1, vp2;
		LL sum = 0;
		for (auto [x, y, w, c] : vp)
		{
			if (fa[x] != y) swap(x, y);
			LL tot = sz[x];
			sum += tot * w;
			while (w)
			{
				if (c == 1) vp1.push_back((w - w / 2) * tot);
				else vp2.push_back((w - w / 2) * tot);
				w /= 2;
			}
		}
		if (sum <= s)
		{
			puts("0");
			continue;
		}
		sum -= s;
		sort(vp1.begin(), vp1.end());
		vp1.push_back(0);
		reverse(vp1.begin(), vp1.end());
		sort(vp2.begin(), vp2.end());
		vp2.push_back(0);
		reverse(vp2.begin(), vp2.end());
		for (int i = 1; i < vp1.size(); i++) vp1[i] += vp1[i - 1];
		for (int i = 1; i < vp2.size(); i++) vp2[i] += vp2[i - 1];
		int ans = INF;
		for (int i = 0; i < vp2.size(); i++)
		{
			while (!vp1.empty() && vp2[i] + vp1.back() >= sum)
			{
				ans = min(ans, i * 2 + (int)vp1.size() - 1);
				vp1.pop_back();
			}
			if (vp1.empty()) vp1.push_back(0);
		}
		printf("%d\n", ans);
	}
	return 0;
}