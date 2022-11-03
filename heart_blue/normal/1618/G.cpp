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
const int N = 4e5 + 10;
class UnionFind
{
public:
	int p[N];
	priority_queue<int> pq1[N];
	priority_queue<int, vector<int>, greater<int>> pq2[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
	}
	int add(int x, int val, int o)
	{
		if (o == 0)
		{
			pq1[x].emplace(val);
			return 0;
		}
		else
		{
			pq2[x].emplace(val);
			return val;
		}
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
	LL Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (px == py) return 0;
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
		LL delta = 0;
		int maxv = pq2[px].size() + pq2[py].size();
		while (!pq1[py].empty())
		{
			pq1[px].push(pq1[py].top());
			pq1[py].pop();
		}
		while (!pq2[py].empty())
		{
			LL x = pq2[py].top();
			pq2[px].push(x);
			pq2[py].pop();
		}
		auto& p1 = pq1[px];
		auto& p2 = pq2[px];
		while (!p1.empty() && !p2.empty() && p1.top() > p2.top())
		{
			int x = p1.top();
			int y = p2.top();
			p1.pop();
			p1.push(y);
			p2.pop();
			p2.push(x);
			delta += x - y;
		}
		return delta;
	}
} uf;
LL ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		vp.emplace_back(x, 1);
	}
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		vp.emplace_back(x, 0);
	}
	vector<pair<int, int>> edge;
	sort(vp.begin(), vp.end());
	LL cur = 0;
	for (int i = 0; i < vp.size(); i++)
	{
		auto [x, o] = vp[i];
		cur += uf.add(i, x, o);
		if (i + 1 < vp.size())
		{
			auto [y, oo] = vp[i + 1];
			edge.emplace_back(y - x, i);
		}
	}
	sort(edge.rbegin(), edge.rend());
	vector<pair<int, int>> qr;
	for (int i = 1; i <= q; i++)
	{
		int x;
		scanf("%d", &x);
		qr.emplace_back(x, i);
	}
	sort(qr.begin(), qr.end());

	for (auto [x, id] : qr)
	{
		while (!edge.empty())
		{
			auto [len, u] = edge.back();
			if (len > x) break;
			edge.pop_back();
			int v = u + 1;
			cur += uf.Union(u, v);
		}
		ans[id] = cur;
	}
	for (int i = 1; i <= q; i++)
		printf("%lld\n", ans[i]);
	return 0;

}