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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class UnionSet
{
public:
	int fa[N];
	int sz[N];
	void init()
	{
		MEM(fa, -1);
		MEM(sz, 0);
	}
	void add(int x)
	{
		x = Find(x);
		sz[x] ++;
	}
	int getSize(int x)
	{
		x = Find(x);
		return sz[x];
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
		int tot = sz[px] + sz[py];
		if (fa[px] > fa[py]) swap(px, py);
		int s = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = s;
		sz[px] = tot;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int x, y;
	uf.init();
	while (m--)
	{
		cin >> x >> y;
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
		}
		uf.add(x);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) == i)
		{
			if (uf.treesize(i) > uf.getSize(i)) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}