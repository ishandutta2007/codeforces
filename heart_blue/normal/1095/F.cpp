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
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int n, m;
	scanf("%d%d", &n, &m);
	int key = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if (a[i] < a[key])
			key = i;
	}
	vector<tuple<LL, int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		vp.emplace_back(a[i] + a[key], i, key);
	}
	while (m--)
	{
		int x, y;
		LL w;
		scanf("%d%d%lld", &x, &y, &w);
		vp.emplace_back(w, x, y);
	}
	sort(vp.begin(), vp.end());
	LL ans = 0;
	for (auto& p : vp)
	{
		int l, r;
		LL w;
		tie(w, l, r) = p;
		if (uf.Find(l) == uf.Find(r)) continue;
		uf.Union(l, r);
		ans += w;
	}
	cout << ans;
	return 0;
}