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
const int N = 1e5 + 10;
const int M = 20;
int fa[N][M];
vector<int> vp[N], v[N];
int in[N], out[N];
int depth[N];
int cnt = 0;
void dfs(int x, int p = 0)
{
	fa[x][0] = p;
	depth[x] = depth[p] + 1;
	in[x] = ++cnt;
	vp[depth[x]].push_back(in[x]);
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
	out[x] = cnt;
}
void init(int n)
{
	for (auto &x : v[0]) dfs(x);
	for (int o = 1; o < 20; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			fa[i][o] = fa[fa[i][o - 1]][o - 1];
		}
	}
}
int moveup(int x, int d)
{
	for (int i = 0; (1 << i) <= d; i++)
	{
		if (d >> i & 1) x = fa[x][i];
	}
	return x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int p;
		cin >> p;
		v[p].push_back(i);
	}
	init(n);
	int q;
	cin >> q;
	while (q--)
	{
		int x, p;
		cin >> x >> p;
		auto &vi = vp[depth[x]];
		x = moveup(x, p);
		if (x == 0) printf("0 ");
		else printf("%d ", upper_bound(vi.begin(), vi.end(), out[x]) - lower_bound(vi.begin(), vi.end(), in[x]) - 1);
	}
	return 0;
}