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
pair<int, int> p[N];
int k[N];
class UnionSet
{
public:
	int fa[N];
	void init(int n = N)
	{
		memset(fa, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -fa[Find(x)];
	}
	int Find(int x)
	{
		int root = x;
		while (fa[root] >= 0) root = fa[root];
		while (x != root)
		{
			int tmp = fa[x];
			fa[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].first, &p[i].second);
	vector<tuple<LL, int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		vp.emplace_back(x, 0, i);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			LL d = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
			vp.emplace_back((k[i] + k[j]) * d, i, j);
		}
	}
	sort(vp.begin(), vp.end());
	vector<int> ans1;
	vector<pair<int, int>> ans2;
	LL cost = 0;
	for (auto& p : vp)
	{
		LL w;
		int x, y;
		tie(w, x, y) = p;
		if (uf.Find(x) == uf.Find(y)) continue;
		uf.Union(x, y);
		if (x == 0) ans1.emplace_back(y);
		else ans2.emplace_back(x, y);
		cost += w;
	}
	printf("%lld\n", cost);
	printf("%d\n", ans1.size());
	for (auto& x : ans1)
		printf("%d ", x);
	puts("");
	printf("%d\n", ans2.size());
	for (auto& p : ans2)
		printf("%d %d\n", p.first, p.second);

	return 0;
}