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
const int N = 1e5 + 10;
class UnionFind
{
public:
	int p[N];
	LL w[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -p[Find(x)];
	}
	void add(int x, LL len)
	{
		w[Find(x)] += len;
	}
	LL getval(int x)
	{
		return w[Find(x)];
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
		w[px] += w[py];
		p[py] = px;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, p, q;
	scanf("%d%d%d%d", &n, &m, &p, &q);
	int cur = n;
	uf.init();
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		if (uf.Find(x) != uf.Find(y))
			uf.Union(x, y), cur--;
		uf.add(x, w);
	}
	if (cur < q || cur - p > q)
	{
		puts("NO");
		return 0;
	}
	if (n == 1)
	{
		if (p > 0) puts("NO");
		else puts("YES");
		return 0;
	}
	if (q == n && p > 0)
	{
		puts("NO");
		return 0;
	}
	using Node = pair<LL, int>;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) != i) continue;
		pq.emplace(uf.getval(i), i);
	}
	vector<pair<int, int>> ans;
	while (cur > q)
	{
		auto [w1, x] = pq.top();
		pq.pop();
		auto [w2, y] = pq.top();
		pq.pop();
		LL w = min(1000000000LL, w1 + w2 + 1);
		uf.Union(x, y);
		uf.add(x, w);
		pq.emplace(uf.getval(x), uf.Find(x));
		cur--, p--;
		ans.emplace_back(x, y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (i != uf.Find(i))
		{
			int j = uf.Find(i);
			while (p--)
				ans.emplace_back(i, j);
			break;
		}
	}
	puts("YES");
	for (auto [x, y] : ans)
		printf("%d %d\n", x, y);
	return 0;
}