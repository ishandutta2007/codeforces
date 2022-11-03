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
const int N = 4e5 + 10;
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
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	uf.init();
	for (int i = 1; i < n; i++)
	{
		int x, y, o;
		scanf("%d%d%d", &x, &y, &o);
		flag[x] |= 1 << o;
		flag[y] |= 1 << o;
		uf.Union(x + o * n, y + o * n);
	}
	LL ans = 0;
	for (int i = 1; i <= 2 * n; i++)
	{
		if (uf.Find(i) != i) continue;
		int sz = uf.treesize(i);
		ans += 1LL * sz * (sz - 1);
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] != 3) continue;
		ans += 1LL * (uf.treesize(i) - 1) * (uf.treesize(i + n) - 1);
	}
	printf("%lld\n", ans);
	return 0;
}