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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int flag[N];
LL ans[N];
class UnionSet
{
public:
	int fa[N];
	LL sum[N];
	void init(int n)
	{
		MEM(fa, -1);
		for (int i = 1; i <= n; i++) cin >> sum[i];
	}
	LL getsum(int x)
	{
		int px = Find(x);
		return sum[px];
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
		LL s = sum[px] + sum[py];
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
		sum[px] = s;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	uf.init(n);
	for (int i = 1; i <= n; i++) cin >> a[i];
	MEM(flag, 0);
	LL maxv = 0;
	ans[n] = 0;
	for (int i = n; i >= 1; i--)
	{
		int p = a[i];
		flag[p] = 1;
		if (flag[p - 1]) uf.Union(p - 1, p);
		if (flag[p + 1]) uf.Union(p + 1, p);
		maxv = max(maxv, uf.getsum(p));
		ans[i-1] = maxv;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}