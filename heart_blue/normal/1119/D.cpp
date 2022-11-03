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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class UnionSet
{
public:
	int fa[N];
	void init(int n = N)
	{
		memset(fa, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -fa[Find(x)];
	}
	int Find(int x)
	{
		int root = x;
		while (fa[root] >= 0) root = fa[root];
		while (x != root)
		{
			int tmp = fa[x];
			fa[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
	}
} uf;
LL ans[N];
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	vector<pair<LL, int>> vp, qr;
	for (int i = 1; i < n; i++)
	{
		vp.emplace_back(a[i + 1] - a[i], i);
	}
	sort(vp.begin(), vp.end());
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		LL l, r;
		scanf("%lld%lld", &l, &r);
		qr.emplace_back(r - l, i);
	}
	sort(qr.begin(), qr.end());
	int ptr = 0;
	int tot = n;
	LL cur = 0;
	for (auto& p : qr)
	{
		LL len;
		int pos;
		tie(len, pos) = p;
		while (ptr < vp.size() && vp[ptr].first <= len)
		{
			int x = vp[ptr].second;
			cur += a[x + 1] - a[x];
			tot--;
			uf.Union(x, x + 1);
			ptr++;
		}
		ans[pos] = cur + tot * (len + 1);
	}
	for (int i = 1; i <= q; i++)
		printf("%lld ", ans[i]);
	return 0;
}