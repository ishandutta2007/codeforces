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
const int N = 2e3 + 10;
class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -p[Find(x)];
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
	}
} uf;
void check(int x, int y)
{
	if (uf.Find(x) != uf.Find(y))
		uf.Union(x, y);
}
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v1, v2;
	while (m--)
	{
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
		{
			v1.emplace_back(l, r);
			for (int i = l + 1; i <= r; i++)
			{
				check(i - 1, i);
			}
		}
		else
			v2.emplace_back(l, r);
	}
	int cur = n;
	for (int i = 1; i <= n; i++)
	{
		int p = uf.Find(i);
		if (ans[p] == 0)
			ans[p] = cur--;
		ans[i] = ans[p];
	}
	for (auto& p : v2)
	{
		int l, r;
		tie(l, r) = p;
		int flag = 0;
		for (int i = l; i < r; i++)
		{
			if (ans[i] > ans[i + 1])
			{
				flag = 1;
			}
		}
		if (flag == 0) puts("NO"), exit(0);
	}
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}