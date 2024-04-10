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
const int block = sqrt(N);
vector<int> v[N];
int in[N];
int out[N];
int ans[N];
int depth[N];
int dfn = 1;
vector<int> vd[2];
void dfs(int x, int fa = -1)
{
	in[x] = dfn++;
	depth[x] = 0;
	if (fa != -1) depth[x] = depth[fa] + 1;
	vd[depth[x] & 1].push_back(in[x]);
	for (auto &y : v[x])
	{
		if (fa == y) continue;
		dfs(y, x);
	}
	out[x] = dfn;
}
class BIT
{
public:
	int a[N];
	int lowbit(int x)
	{
		return x&-x;
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= lowbit(x);
		}
		return ret;
	}
	void add(int x, int y)
	{
		while (x < N)
		{
			a[x] += y;
			x += lowbit(x);
		}
	}
} b[2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &ans[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	while (m--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			for (int i = 0; i < 2; i++)
			{
				int val = y;
				if ((depth[x] - i) & 1)
				{
					val = -y;
				}
				int l = lower_bound(vd[i].begin(), vd[i].end(), in[x]) - vd[i].begin() + 1;
				int r = lower_bound(vd[i].begin(), vd[i].end(), out[x]) - vd[i].begin() + 1;
				b[i].add(l, val);
				b[i].add(r, -val);
			}
		}
		else
		{
			int x;
			scanf("%d", &x);
			int o = depth[x] & 1;
			int pos = lower_bound(vd[o].begin(), vd[o].end(), in[x]) - vd[o].begin() + 1;
			printf("%d\n", ans[x] + b[o].sum(pos));
		}
	}
	return 0;
}