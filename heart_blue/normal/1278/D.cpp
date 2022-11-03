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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
int key[N];
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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	uf.init();
	set<pair<int, int>> sp;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		key[i] = l;
		a[l] = i;
		a[r] = -i;
	}
	for (int i = 1; i <= 2 * n; i++)
	{
		int x = a[i];
		if (a[i] > 0)
		{
			sp.emplace(key[x], x);
		}
		else
		{
			x = -x;
			sp.erase(make_pair(key[x], x));
			auto iter = sp.rbegin();
			while (iter != sp.rend())
			{
				auto [l, y] = *iter;
				iter++;
				if (l < key[x]) break;
				if (uf.Find(x) == uf.Find(y))
				{
					puts("NO");
					return 0;
				}
				uf.Union(x, y);
			}
		}
	}
	if (uf.treesize(1) == n) puts("YES");
	else puts("NO");
	return 0;
}