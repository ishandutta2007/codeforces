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
private:
	int p[N];
public:
	int size(int x)
	{
		int px = Find(x);
		return -p[px];
	}
	void init()
	{
		MEM(p, -1);
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
int a[N];
vector<int> v[N];
int dis[N];
vector<pair<int, int>> vp;
int n;
void dfs(int x, int p = -1)
{
	if (dis[x]) return;
	dis[x] = 1;
	if (p != -1) dis[x] += dis[p];
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
int solve(int rt)
{
	MEM(dis, 0);
	dfs(rt);
	for (int i = 1; i <= n; i++)
	{
		if (dis[rt] < dis[i]) rt = i;
	}
	MEM(dis, 0);
	dfs(rt);
	for (int i = 1; i <= n; i++)
	{
		if (dis[rt] < dis[i]) rt = i;
	}
	return dis[rt] / 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	vp.resize(n - 1);
	for (auto &p : vp)
	{
		cin >> p.first >> p.second;
		int x, y;
		tie(x, y) = p;
		if (a[x] == a[y] && uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
		}
	}
	for (auto &p : vp)
	{
		int x, y;
		tie(x, y) = p;
		int px = uf.Find(x), py = uf.Find(y);
		if (px == py) continue;
		v[px].push_back(py);
		v[py].push_back(px);
	}
	cout << solve(uf.Find(1)) << endl;
	return 0;
}