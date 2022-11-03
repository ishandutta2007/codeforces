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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int fa[N][20];
vector<int> fv[N][20];
vector<int> v[N];
int depth[N];
void refrain(vector<int> &v)
{
	sort(v.begin(), v.end());
	while (v.size() > 10) v.pop_back();
}
vector<int> comb(const vector<int> &v1, const vector<int> &v2)
{
	vector<int> v;
	v = v1;
	for (auto &x : v2) v.push_back(x);
	refrain(v);
	return v;
}
void dfs(int x, int p = 0)
{
	fa[x][0] = p;
	refrain(fv[x][0]);
	depth[x] = depth[p] + 1;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
void init(int n)
{
	dfs(1);
	for (int o = 0; o + 1 < 20; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			fa[i][o + 1] = fa[fa[i][o]][o];
			fv[i][o + 1] = comb(fv[i][o], fv[fa[i][o]][o]);
		}
	}
}
int moveup(int x, int d)
{
	for (int o = 0; 1 << o <= d; o++)
	{
		if (d >> o & 1) x = fa[x][o];
	}
	return x;
}
int getlca(int x, int y)
{
	if (depth[x] < depth[y]) swap(x, y);
	x = moveup(x, depth[x] - depth[y]);
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
	{
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}
vector<int> getans(int x, int d)
{
	vector<int> ret;
	for (int o = 0; 1 << o <= d; o++)
	{
		if (d >> o & 1) ret = comb(ret, fv[x][o]), x = fa[x][o];
	}
	return ret;
}
void solve(int x, int y, int k)
{
	int lca = getlca(x, y);
	vector<int> ret = fv[lca][0];
	ret = comb(ret, getans(x, depth[x] - depth[lca]));
	ret = comb(ret, getans(y, depth[y] - depth[lca]));
	if (k > ret.size()) k = ret.size();
	printf("%d", k);
	for (int i = 0; i < k; i++) printf(" %d", ret[i]);
	puts("");
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		fv[x][0].push_back(i);
	}
	init(n);
	while (q--)
	{
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		solve(x, y, k);
	}
	return 0;
}