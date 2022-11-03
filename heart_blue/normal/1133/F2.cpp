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
const int N = 2e5 + 10;
vector<int> v[N];
class UnionFind
{
public:
	int p[N];
	int val[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -p[Find(x)];
	}
	void setval(int x)
	{
		val[x] = 1;
	}
	int getval(int x)
	{
		return val[Find(x)];
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
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
		val[px] |= val[py];
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	uf.init();
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		v[x].push_back(y);
		if (x == 1 || y == 1)
			uf.setval(x ^ y ^ 1);
	}
	vector<pair<int, int>> ans;
	for (int i = 2; i <= n; i++)
	{
		for (auto& j : v[i])
		{
			if (uf.Find(i) == uf.Find(j)) continue;
			if (uf.getval(i) + uf.getval(j) == 2) continue;
			uf.Union(i, j);
			ans.emplace_back(i, j);
		}
	}
	int tot = v[1].size();
	for (int i = 2; i <= n; i++)
	{
		for (auto& j : v[i])
		{
			if (uf.Find(i) == uf.Find(j)) continue;
			if (uf.getval(i) + uf.getval(i) != 2) continue;
			if (tot <= k) break;
			tot--;
			uf.Union(i, j);
			ans.emplace_back(i, j);
		}
	}
	if (tot != k) puts("NO"), exit(0);
	for (auto& x : v[1])
	{
		if (uf.Find(x) == uf.Find(1)) continue;
		uf.Union(1, x);
		ans.emplace_back(1, x);
		tot--;
	}
	if (tot != 0) puts("NO"), exit(0);
	puts("YES");
	for (auto& p : ans)
	{
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}