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
const int N = 5e5 + 10;
set<int> s;
vector<int> v[N];
vector<int> ans[N];
class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int)*n);
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
		while (x != s)
		{
			int t = p[x];
			p[x] = s;
			x = t;
		}
		return s;
	}
	int treesize(int x)
	{
		return -p[Find(x)];
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (treesize(px) < treesize(py)) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
void dfs(int x, int p = -1)
{
	if (p != -1)
	{
		if (uf.Find(x) != uf.Find(p))
		{
			uf.Union(x, p);
		}
	}
	s.erase(x);
	if (s.empty()) return;
	for (int i = 0; i + 1 < v[x].size(); i++)
	{
		int y = v[x][i];
		int z = v[x][i + 1];
		auto iter = s.upper_bound(y);
		if (iter == s.end()) break;
		if (*iter < z)
		{
			dfs(*iter, x);
			i--;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	uf.init();
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		v[i].push_back(0);
		v[i].push_back(n + 1);
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 1; i <= n; i++) s.insert(i);
	while (!s.empty())
	{
		dfs(*s.begin());
	}
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		ans[uf.Find(i)].push_back(i);
		if (uf.Find(i) == i) tot++;
	}
	printf("%d\n", tot);
	for (int i = 1; i <= n; i++)
	{
		if (ans[i].empty()) continue;
		printf("%d", ans[i].size());
		for (auto &x : ans[i]) printf(" %d", x);
		puts("");
	}
	return 0;
}