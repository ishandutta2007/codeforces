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

class UnionSet
{
public:
	int fa[N];
	int nex[N];
	void init()
	{
		MEM(fa, -1);
		for (int i = 0; i < N; i++) nex[i] = i;
	}
	int getnext(int x)
	{
		int p = Find(x);
		return nex[p];
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
		int o = max(nex[px], nex[py]);
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
		nex[px] = o;
	}
} uf;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(b, 0);
	uf.init();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = INF;
	int q;
	cin >> q;
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int p, x;
			cin >> p >> x;
			while (1)
			{
				p = uf.getnext(p);
				int o = min(x, a[p] - b[p]);
				x -= o;
				b[p] += o;
				if (x == 0) break;
				if (p == n) break;
				uf.Union(p, p + 1);
			}
		}
		else
		{
			int x;
			cin >> x;
			cout << b[x] << '\n';
		}
	}
	return 0;
}