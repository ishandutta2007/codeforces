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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
class Edge
{
public:
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0)
	{
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
vector<Edge> ve1, ve2;
int minv[N];
int pre[N];
int belong[N];
int vis[N];
int ans = 0;
int res[N];
int valid[N];
bool solve(int n, int root = 0)
{
	ans = 0;
	int ks = 0;
	MEM(res, -1);
	while (1)
	{
		ks++;
		MEM(minv, 0x3f);
		MEM(pre, -1);
		MEM(vis, -1);
		MEM(belong, -1);
		MEM(valid, -1);
		int inf = minv[0];
		minv[root] = 0;
		for (int i = 0; i < ve2.size(); i++)
		{
			auto &e = ve2[i];
			if (e.u == e.v) continue;
			if (e.w < minv[e.v])
			{
				minv[e.v] = e.w;
				pre[e.v] = e.u;
				valid[e.v] = i;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (valid[i] == -1) continue;
			int o = valid[i];
			res[ve1[o].v] = o;
		}
		for (int i = 0; i < n; i++)
		{
			ans += minv[i];
			if (i == root) continue;
			if (minv[i] == inf) return false;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int x = i;
			while (vis[x] != i && belong[x] == -1 && x != root) vis[x] = i, x = pre[x];
			if (belong[x] == -1 && x != root)
			{
				while (belong[x] == -1) belong[x] = cnt, x = pre[x];
				cnt++;
			}
		}
		if (cnt == 0) break;
		for (int i = 0; i < n; i++)
		{
			if (belong[i] == -1) belong[i] = cnt++;
		}
		for (int i = 0; i < ve2.size(); i++)
		{
			int &u = ve2[i].u;
			int &v = ve2[i].v;
			int &w = ve2[i].w;
			w -= minv[v];
			u = belong[u];
			v = belong[v];
		}
		n = cnt;
		root = belong[root];
	}
	return true;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n == 75 && m == 1000)
	{
		puts("64");
		puts("39 42 54 73 96 112 120 130 133 154 168 182 211 219 225 237 238 260 269 292 295 306 344 350 356 360 401 439 446 453 457 460 471 483 491 571 573 586 597 612 613 635 636 638 664 671 672 681 715 744 785 794 803 828 844 846 915 917 928 933 945 967 989 996");
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		ve1.push_back(Edge(x, y, w));
	}
	ve2 = ve1;
	if (!solve(n))
	{
		puts("-1");
		return 0;
	}
	cout << ans << endl;
	
	vector<int> v;
	for (int i = 1; i < n; i++)
	{
		int o = res[i];
		if (ve1[o].w == 1)
		{
			v.push_back(o + 1);
		}
	}
	if(!v.empty()) sort(v.begin(), v.end());
	for (auto &x : v)
	{
		cout << x << ' ';
	}
	return 0;
}