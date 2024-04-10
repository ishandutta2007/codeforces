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
const int N = 2e5 + 10;
const int M = 5e2 + 10;
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
	void init()
	{
		MEM(p, -1);
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
int belong[N];
int a[M][M];
void floyd(int n)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int sum = k;
	uf.init();
	MEM(a, 0x3f);
	for (int i = 1; i <= k; i++)
	{
		a[i][i] = 0;
		int x;
		cin >> x;
		uf.Union(sum + 1, i);
		for (int o = 1; o <= x; o++)
		{
			belong[sum + o] = i;
		}
		sum += x;
	}
	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x += k, y += k;
		if (w == 0)
		{
			if (uf.Find(x) != uf.Find(y))
			{
				uf.Union(x, y);
			}
		}
		x = belong[x];
		y = belong[y];
		a[x][y] = a[y][x] = min(a[x][y], w);
	}
	for (int i = k + 1; i <= k + n; i++)
	{
		if (uf.Find(i) != uf.Find(belong[i]))
		{
			puts("No");
			return 0;
		}
	}
	floyd(k);
	puts("Yes");
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			printf("%d%c", a[i][j] == 0x3f3f3f3f ? -1 : a[i][j], " \n"[j == k]);
		}
	}
	return 0;
}