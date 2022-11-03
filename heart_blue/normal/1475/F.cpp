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
const int N = 1e3 + 10;
class UnionFind
{
public:
	int p[N * 4];
	void init(int n = N * 4)
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
		if (Find(x) == Find(y)) return;
		int px = Find(x);
		int py = Find(y);
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
char str[N][N];
char s[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		uf.init();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s);
			for (int j = 0; j < n; j++)
			{
				int x = i, y = j + n;
				int o = s[j] != str[i][j];
				if (o) uf.Union(x, y + 2 * n), uf.Union(x + 2 * n, y);
				else uf.Union(x, y), uf.Union(x + 2 * n, y + 2 * n);
			}
		}
		int flag = 1;
		for (int i = 0; i < 2 * n; i++)
		{
			if (uf.Find(i) == uf.Find(i + 2 * n))
			{
				flag = 0;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}