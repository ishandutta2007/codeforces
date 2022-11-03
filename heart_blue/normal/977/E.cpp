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
	int a[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int)*n);
		memset(a, 0, sizeof(int)*n);
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
		if (px == py)
		{
			a[px]++;
			return;
		}
		int tot = a[px] + a[py] + 1;
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
		a[px] = tot;
	}
	int getedge(int x)
	{
		return a[Find(x)];
	}
} uf;
int deg[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	uf.init();
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		deg[x]++;
		deg[y]++;
		uf.Union(x, y);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] != 2)
			flag[uf.Find(i)] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) == i)
		{
			if (flag[i] == 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}