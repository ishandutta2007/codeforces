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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
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
		if (px == py) return;
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<tuple<int, int, int, int>> vp;
	vector<int> v;
	while (m--)
	{
		int a, b, l, r;
		scanf("%d%d%d%d", &a, &b, &l, &r);
		vp.emplace_back(r, l, a, b);
		v.push_back(l);
	}
	sort(vp.rbegin(), vp.rend());
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto& x : v)
	{
		uf.init();
		for (auto& [r, l, a, b] : vp)
		{
			if (l > x) continue;
			uf.Union(a, b);
			if (uf.Find(1) == uf.Find(n))
			{
				ans = max(ans, r - x + 1);
			}
		}
	}
	if (ans > 0) printf("%d\n", ans);
	else puts("Nice work, Dima!");
	return 0;
}