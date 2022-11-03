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
class UnionSet
{
public:
	int fa[N];
	void init(int n = N)
	{
		memset(fa, -1, sizeof(int) * n);
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
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
	}
} uf;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	uf.init();
	int m;
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		if (uf.Find(x) != uf.Find(y))
			uf.Union(x, y);
	}
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		if (uf.Find(x) == uf.Find(y))
			flag[uf.Find(x)] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) != i || flag[i]) continue;
		ans = max(ans, uf.treesize(i));
	}
	cout << ans << endl;
	return 0;
}