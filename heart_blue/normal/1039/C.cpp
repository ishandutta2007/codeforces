#pragma comment(linker, "/STACK:102400000,102400000") 
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
const int N = 5e5 + 10;
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
LL a[N];
vector<pair<int, int>> vp[N];
vector<LL> v;
map<LL, int> mc;
template <class T>
inline void readint(T &ret)
{
	char c;
	ret = 0;
	while ((c = getchar()) < '0' || c > '9');
	while (c >= '0' && c <= '9')
	{
		ret = ret * 10 + (c - '0'), c = getchar();
	}
}
LL p2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	p2[0] = 1;
	for (int i = 1; i < N; i++)
	{
		p2[i] = p2[i - 1] * 2;
		if (p2[i] >= INF) p2[i] -= INF;
	}
	uf.init();
	int n, m, k;
	readint(n);
	readint(m);
	readint(k);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		readint(a[i]);
	}
	int cur = 0;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		readint(x);
		readint(y);
		LL o = a[x] ^ a[y];
		if (!mc.count(o))
		{
			mc[o] = cur;
			v.push_back(o);
			cur++;
		}
		int pos = mc[o];
		vp[pos].push_back({ x,y });
	}
	for (int i = 0; i < cur; i++)
	{
		int tot = n;
		for (auto &p : vp[i])
		{
			int x, y;
			tie(x, y) = p;
			if (uf.Find(x) != uf.Find(y))
				uf.Union(x, y), tot--;
		}
		ans += p2[tot];
		if (ans >= INF) ans -= INF;
		for (auto &p : vp[i])
		{
			int x, y;
			tie(x, y) = p;
			uf.fa[x] = -1;
			uf.fa[y] = -1;
		}
	}
	LL rest = 1LL << k;
	rest -= cur;
	rest %= INF;
	ans = (ans + p2[n] * rest) % INF;
	printf("%lld\n", ans);
	return 0;
}