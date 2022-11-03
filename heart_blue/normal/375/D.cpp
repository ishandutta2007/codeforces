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
const int M = 320;
class BIT
{
public:
	int a[N];
	inline int lowbit(int x)
	{
		return x & -x;
	}
	void add(int x, int y)
	{
		if (x <= 0) return;
		while (x < N)
		{
			a[x] += y;
			x += lowbit(x);
		}
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
} b;
int in[N];
int out[N];
int c1[N];
int c2[N];
int cnt = 0;
vector<int> v[N];
int tot[N];
int ans[N];
struct Node
{
	int l, r, k, pos;
	bool operator < (const Node& node) const
	{
		if (l / M != node.l / M) return l / M < node.l / M;
		return r < node.r;
	}
} qr[N];
void dfs(int x, int p = 0)
{
	in[x] = ++cnt;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
	out[x] = cnt;
}
void add(int x, int o)
{
	x = c2[x];
	b.add(tot[x], -1);
	tot[x] += o;
	b.add(tot[x], 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &c1[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) c2[in[i]] = c1[i];
	for (int i = 1; i <= q; i++)
	{
		int u, k;
		scanf("%d%d", &u, &k);
		qr[i].l = in[u];
		qr[i].r = out[u];
		qr[i].k = k;
		qr[i].pos = i;
	}
	sort(qr + 1, qr + q + 1);
	int L = 1, R = 0;
	for (int i = 1; i <= q; i++)
	{
		int l, r, k;
		l = qr[i].l, r = qr[i].r, k = qr[i].k;
		while (R < r) add(++R, 1);
		while (L < l) add(L++, -1);
		while (R > r) add(R--, -1);
		while (L > l) add(--L, 1);
		ans[qr[i].pos] = b.sum(N - 1) - b.sum(k - 1);
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}