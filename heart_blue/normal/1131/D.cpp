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
const int N = 2e3 + 10;
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
char str[N][N];
int deg[N];
int ans[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			int x = i, y = j + n;
			if (str[i][j] == '=')
			{
				uf.Union(x, y);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x = uf.Find(i), y = uf.Find(j + n);
			if (str[i][j] == '=') continue;
			if (str[i][j] == '>') swap(x, y);
			v[x].push_back(y);
			deg[y]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n + m; i++)
	{
		if (deg[i] == 0)
			q.push(i), ans[i] = 1;
	}
	int rest = n + m;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		rest--;
		for (auto& y : v[x])
		{
			if (deg[y]-- == 1)
				q.push(y);
			ans[y] = max(ans[y], ans[x] + 1);
		}
	}
	if (rest > 0)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for (int i = 1; i <= n + m; i++)
	{
		printf("%d%c", ans[uf.Find(i)], " \n"[i == n || i == n + m]);
	}
	return 0;
}