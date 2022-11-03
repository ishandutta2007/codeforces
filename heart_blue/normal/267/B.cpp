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
const int N = 2e1 + 10;
vector<int> v[N][N];
int cnt[N][N];
int deg[N];
int flag[N];
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
vector<pair<int, int>> ans;
void dfs(int x)
{
	for (int i = 0; i <= 6; i++)
	{
		if (i == x && cnt[i][i] > 0)
		{
			cnt[x][x]--;
			dfs(x);
			ans.emplace_back(x, x);
			continue;
		}
		if (cnt[x][i])
		{
			cnt[x][i]--;
			cnt[i][x]--;
			dfs(i);
			ans.emplace_back(x, i);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	uf.init();
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		flag[x] = flag[y] = 1;
		if (x == y)
		{
			cnt[x][x]++;
			v[x][x].push_back(i);
			continue;
		}
		cnt[x][y]++;
		cnt[y][x]++;
		deg[x]++;
		deg[y]++;
		v[x][y].push_back(i);
		if (uf.Find(x) != uf.Find(y))
			uf.Union(x, y);
	}
	int key = x;
	int tot = 0;
	int err = 0;
	for (int i = 0; i <= 6; i++)
	{
		if (flag[i]) tot++;
		if (deg[i] & 1) key = i, err++;
	}
	if (uf.treesize(x) != tot || err > 2)
	{
		puts("No solution");
		return 0;
	}
	dfs(key);
	reverse(ans.begin(), ans.end());
	for (auto& p : ans)
	{
		int x, y;
		tie(x, y) = p;
		//printf("%d %d\n", x, y);
		if (!v[x][y].empty())
		{
			printf("%d +\n", v[x][y].back());
			v[x][y].pop_back();
		}
		else
		{
			printf("%d -\n", v[y][x].back());
			v[y][x].pop_back();
		}
	}
	return 0;
}