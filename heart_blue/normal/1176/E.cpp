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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
class UnionFind
{
private:
	int p[N];
public:
	int size(int x)
	{
		int px = Find(x);
		return -p[px];
	}
	void init(int n)
	{
		memset(p, -1, sizeof(int)*n);
	}
	int Find(int x)
	{
		int root = x;
		while (p[root] >= 0) root = p[root];
		while (x != root)
		{
			int tmp = p[x];
			p[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (size(px) > size(py)) swap(px, py);
		int total = size(px) + size(py);
		p[px] = py;
		p[py] = -total;
	}
} uf;
vector<int> v[N];
int col[N];
vector<int> ans[2];
void dfs(int x, int o = 0)
{
	if (col[x] != -1) return;
	ans[o].push_back(x);
	col[x] = o;
	for (auto &y : v[x])
		dfs(y, o ^ 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) v[i].clear();
		uf.init(n + 1);
		while (m--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (uf.Find(x) == uf.Find(y)) continue;
			uf.Union(x, y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		memset(col, -1, sizeof(int)*(n + 1));
		ans[0].clear();
		ans[1].clear();
		dfs(1);
		int o = 0;
		if (ans[o].size() > ans[o ^ 1].size()) o ^= 1;
		printf("%d\n", ans[o].size());
		for (auto &x : ans[o]) printf("%d ", x);
		puts("");
	}
	return 0;
}