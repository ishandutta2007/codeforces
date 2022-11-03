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

class UnionFind
{
public:
	int p[N];
	void init(int n = N)
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
		int px = Find(x);
		int py = Find(y);
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
map<char, int> mc[N];
char str[N];
void check(int l, int r)
{
	while (l <= r)
	{
		if (uf.Find(l) != uf.Find(r))
			uf.Union(l, r);
		l++, r--;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		uf.init(n + 1);
		check(1, n);
		for (int i = k + 1; i <= n; i++)
		{
			if (uf.Find(i) != uf.Find(i - k))
				uf.Union(i, i - k);
		}
		for (int i = 1; i <= n; i++) mc[i].clear();
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++)
		{
			mc[uf.Find(i)][str[i]]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (uf.Find(i) != i) continue;
			int maxv = 0;
			for (auto& p : mc[i])
				maxv = max(maxv, p.second);
			ans += uf.treesize(i) - maxv;
		}
		printf("%d\n", ans);
	}
	return 0;
}