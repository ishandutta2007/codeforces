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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int l[N];
int r[N];
class UnionSet
{
public:
	int fa[N];
	void init()
	{
		MEM(fa, -1);
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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int tot = 0;
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		if (r[i] == 0) tot++;
		if (l[i] != 0)
		{
			if (uf.Find(l[i]) != uf.Find(i))
				uf.Union(l[i], i);
		}
		if (r[i] != 0)
		{
			if (uf.Find(r[i]) != uf.Find(i))
			{
				uf.Union(r[i], i);
			}
		}
	}
	while (tot > 1)
	{
		tot--;
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (r[i] != 0) continue;
			for (int j = 1; j <= n; j++)
			{
				if (l[j] != 0) continue;
				if (uf.Find(i) != uf.Find(j))
				{
					uf.Union(i, j);
					r[i] = j;
					l[j] = i;
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << l[i] << ' ' << r[i] << '\n';
	}
	return 0;
}