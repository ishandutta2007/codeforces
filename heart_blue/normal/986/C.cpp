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
const int N = 5e6 + 10;
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
int flag[N];
int a[N];
bool cnt[N];
int dfs(int x, int o)
{
	if (flag[x] != -1)
	{
		if (flag[x] == 1)
		{
			if (uf.Find(x) != uf.Find(o))
			{
				uf.Union(x, o);
			}
		}
		return flag[x];
	}
	int ok = 0;
	if ((x&o) == 0 && a[x] == 1) ok = 1;
	for (int i = 0; (1 << i) <= x; i++)
	{
		if (x >> i & 1)
		{
			ok |= dfs(x ^ (1 << i), o);
		}
	}
	if (ok)
	{
		if (uf.Find(x) != uf.Find(o))
		{
			uf.Union(x, o);
		}
	}
	return flag[x] = ok;
}
int readint() {
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9')c = getchar();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	n = readint();
	m = readint();
	MEM(flag, -1);
	int mask = (1 << n) - 1;
	for (int i = 1; i <= m; i++)
	{
		int x;
		x = readint();
		a[x] = 1;
	}
	uf.init();
	for (int i = 0; i <= mask; i++)
	{
		if (a[i] == 0) continue;
		dfs(i^mask, i);
	}
	int ans = 0;
	for (int i = 0; i <= mask; i++)
	{
		if (a[i] == 0) continue;
		cnt[uf.Find(i)] = 1;
	}
	for (int i = 0; i <= mask; i++)
	{
		ans += cnt[i];
	}
	printf("%d\n", ans);
	return 0;
}