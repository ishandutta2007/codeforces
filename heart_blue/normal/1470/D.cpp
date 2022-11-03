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
const int N = 3e5 + 10;
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
int flag[N];
vector<int> v[N];
void solve()
{
	queue<int> q;
	q.push(1);
	flag[1] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		int o = 2;
		for (auto& y : v[x])
		{
			if (flag[y] == 2) o = 1;
			if (flag[y]) continue;
			flag[y] = 1;
			q.push(y);
		}
		flag[x] = o;
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
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			v[i].clear();
		uf.init(n + 1);
		fill(flag + 1, flag + n + 1, 0);
		while (m--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			uf.Union(x, y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if (uf.treesize(1) != n)
		{
			puts("NO");
			continue;
		}
		solve();
		puts("YES");
		vector<int> ans;
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] == 2)
				ans.push_back(i);
		}
		printf("%d\n", ans.size());
		for (auto& x : ans)
			printf("%d ", x);
		puts("");

	}
	return 0;
}