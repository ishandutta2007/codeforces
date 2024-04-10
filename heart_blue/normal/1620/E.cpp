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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
int last[N];
int ans[N];
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
		if (px == py) return;
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int q;
	scanf("%d", &q);
	int sz = 0;
	while (q--)
	{
		int op, x, y;
		scanf("%d%d", &op, &x);
		if (op == 1)
		{
			sz++;
			if (last[x] != 0)
			{
				uf.Union(last[x], sz);
			}
			last[x] = sz;
		}
		else
		{
			scanf("%d", &y);
			if (last[x] != 0 && last[y] != 0)
			{
				uf.Union(last[x], last[y]);
			}
			last[y] = max(last[y], last[x]);
			if (x != y)
				last[x] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (last[i] != 0)
		{
			ans[uf.Find(last[i])] = i;
		}
	}
	for (int i = 1; i <= sz; i++)
		printf("%d ", ans[uf.Find(i)]);
	return 0;
}