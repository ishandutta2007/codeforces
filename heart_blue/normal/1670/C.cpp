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
		fill(p, p + n, -1);
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
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		uf.init(n + 10);
		for (int i = 1; i <= n; i++)
		{
			if (uf.Find(a[i]) != uf.Find(b[i]))
				uf.Union(a[i], b[i]);
		}
		map<int, int> mc;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x == 0) continue;
			mc[uf.Find(x)] = 1;
		}
		int ans = 1;
		for (int i = 1; i <= n; i++)
		{
			if (uf.Find(i) != i) continue;
			if (mc[i] == 0 && uf.size(i) > 1)
				ans = ans * 2 % INF;
		}
		printf("%d\n", ans);
	}

	return 0;
}