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
#include <iterator>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int dfn = 1;
int in[N], out[N];
int a[N];
LL dis[N];
int ans[N];
vector<pair<int, LL>> vp[N];
void dfs(int x, int fa = -1)
{
	in[x] = dfn++;
	if (fa == -1) dis[x] = 0;
	for (auto &p : vp[x])
	{
		int y;
		LL w;
		tie(y, w) = p;
		dis[y] = dis[x] + w;
		dfs(y, x);
	}
	out[x] = dfn;
}
class Bit
{
public:
	Bit()
	{
		MEM(val, 0);
	}
	int lowbit(int x)
	{
		return x&-x;
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += val[x];
			x -= lowbit(x);
		}
		return ret;
	}
	void add(int x, int y)
	{
		while (x < N)
		{
			val[x] += y;
			x += lowbit(x);
		}
	}
private:
	int val[N];
};
Bit b;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++)
	{
		int fa, w;
		scanf("%d%d", &fa, &w);
		vp[fa].push_back({ i, w });
	}
	dfs(1);
	vector<pair<LL, int>> vp1, vp2;
	for (int i = 1; i <= n; i++)
	{
		vp1.push_back({ dis[i] - a[i], i });
		vp1.push_back({ dis[i], -i });
		vp2.push_back({ dis[i],i });
	}
	sort(vp1.begin(), vp1.end());
	sort(vp2.begin(), vp2.end());
	int ptr = 0;
	for (auto &p : vp2)
	{
		int u2 = p.second;
		LL tm = p.first;
		while (ptr < vp1.size() && vp1[ptr].first <= tm)
		{
			int u1 = vp1[ptr].second;
			int o;
			if (u1 > 0) o = 1;
			else u1 = -u1, o = -1;
			b.add(in[u1], o);
			ptr++;
		}
		ans[u2] = b.sum(out[u2] - 1) - b.sum(in[u2]);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}