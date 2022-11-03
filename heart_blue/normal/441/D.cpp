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
#include <regex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e3 + 10;
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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cur = 0;
	int n;
	uf.init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (uf.Find(i) != uf.Find(a[i]))
		{
			uf.Union(i, a[i]);
			cur++;
		}
	}
	int m;
	scanf("%d", &m);
	if (cur == m)
	{
		puts("0");
		return 0;
	}
	vector<pair<int, int>> ans;
	if (cur < m)
	{
		for (int i = 2; i <= n; i++)
		{
			if (uf.Find(1) != uf.Find(i))
				uf.Union(1, i), ans.emplace_back(1, i), cur++;
			if (cur == m) break;
		}
	}
	while (cur > m)
	{
		uf.init();
		for (int i = 1; i <= n; i++)
		{
			if (uf.Find(i) != uf.Find(a[i]))
				uf.Union(i, a[i]);
		}
		pair<int, int> p = { n + 1,n + 1 };
		for (int i = 1; i <= n; i++)
		{
			if (uf.treesize(i) == 1) continue;
			int key = -1;
			for (int j = i + 1; j <= n; j++)
			{
				if (uf.Find(i) == uf.Find(j))
				{
					key = j;
					break;
				}
			}
			p = { i,key };
			break;
		}
		auto [x, y] = p;
		swap(a[x], a[y]);
		ans.push_back(p);
		cur--;
	}
	printf("%d\n", ans.size());
	for (auto [a, b] : ans)
		printf("%d %d ", a, b);
	return 0;
}