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
const int N = 1e5 + 10;
class UnionSet
{
public:
	int fa[N];
	void init()
	{
		MEM(fa, -1);
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
int p[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		if (uf.Find(i) != uf.Find(p[i]))
		{
			uf.Union(i, p[i]);
		}
	}
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		if (i == uf.Find(i))
		{
			vp.push_back({ uf.treesize(i),i });
		}
	}
	sort(vp.begin(), vp.end());
	if (vp.front().first > 2)
	{
		puts("NO");
		return 0;
	}
	int sz = vp.size();
	vector<pair<int, int>> ans;
	for (int i = 1; i < sz; i++)
	{
		if (vp[i].first % vp[0].first)
		{
			puts("NO");
			return 0;
		}
		int tot = vp[i].first;
		int x = vp[i].second, y = vp[0].second;
		while (tot--)
		{
			ans.push_back({ x,y });
			x = p[x];
			y = p[y];
		}
	}
	if (vp[0].first == 2)
	{
		int x = vp[0].second;
		ans.push_back({ x, p[x] });
	}
	puts("YES");
	for (auto &p : ans) printf("%d %d\n", p.first, p.second);

	return 0;
}