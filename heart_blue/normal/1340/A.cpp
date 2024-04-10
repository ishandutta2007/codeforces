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
const int N = 2e5 + 20;
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
	void init(int n)
	{
		memset(p, -1, sizeof(int) * n);
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
int pos[N];
map<int, int> mc;
void add(int x)
{
	mc[x]++;
}
void del(int x)
{
	mc[x]--;
	if (mc[x] == 0)
		mc.erase(x);
}
int getmax()
{
	return mc.rbegin()->first;
}
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
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			pos[x] = i;
		}
		int flag = 1;
		uf.init(n + 2);
		mc.clear();
		for (int i = 1; i <= n; i++) mc[1]++;
		for (int i = 1; i <= n; i++)
		{
			if (uf.size(pos[i]) != getmax())
			{
				flag = 0;
				break;
			}
			del(uf.size(pos[i]));
			uf.Union(pos[i], pos[i] + 1);
			if (uf.Find(pos[i]) != uf.Find(n + 1))
			{
				add(uf.size(pos[i]));
			}
		}
		if (flag) puts("Yes");
		else puts("No");
	}
	return 0;
}