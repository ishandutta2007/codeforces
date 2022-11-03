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
vector<tuple<int, int, int>> vp;
LL ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		vp.emplace_back(w, u, v);
	}
	uf.init();
	sort(vp.begin(), vp.end());
	for (auto& p : vp)
	{
		int u, v, w;
		tie(w, u, v) = p;
		ans[w] += 1LL * uf.treesize(u) * uf.treesize(v);
		uf.Union(u, v);
	}
	for (int i = 1; i < N; i++)
	{
		ans[i] += ans[i - 1];
	}
	while (m--)
	{
		int x;
		scanf("%d", &x);
		printf("%lld ", ans[x]);
	}
	return 0;
}