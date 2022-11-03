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
class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int)*n);
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
int w[N];
int vis[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	uf.init();
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		if (uf.Find(i) != uf.Find(x))
			uf.Union(i, x);
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) != i) continue;
		int x = i, y = i;
		while (1)
		{
			x = a[a[x]];
			y = a[y];
			if (x == y) break;
		}
		int maxv = INF;
		while (vis[x] == 0)
		{
			vis[x] = 1;
			maxv = min(maxv, w[x]);
			x = a[x];
		}
		ans += maxv;
	}
	printf("%lld\n", ans);
	return 0;
}