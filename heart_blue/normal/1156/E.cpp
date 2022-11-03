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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
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
int pos[N];
int solve(int l1, int r1, int l2, int r2, int x)
{
	if (r1 - l1 > r2 - l2) swap(l1, l2), swap(r1, r2);
	int ret = 0;
	for (int i = l1; i <= r1; i++)
	{
		int p = pos[x - a[i]];
		if (p >= l2 && p <= r2)
			ret++;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	a[0] = a[n + 1] = INF;
	uf.init();
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int p = pos[i];
		int l = p, r = p;
		if (a[p] > a[p - 1])
		{
			l -= uf.treesize(p - 1);
			uf.Union(p, p - 1);
		}
		if (a[p] > a[p + 1])
		{
			r += uf.treesize(p + 1);
			uf.Union(p, p + 1);
		}
		ans += solve(l, p - 1, p + 1, r, i);
	}
	printf("%d\n", ans);
	return 0;
}