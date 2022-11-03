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
		if (px == py) return;
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int flag[N];
int a[N];
void refrain(vector<tuple<int, int, int>> &vp, int k)
{
	sort(vp.begin(), vp.end());
	for (int i = 0; i + 1 < vp.size(); i++)
	{
		auto [x1, y1, id1] = vp[i];
		auto [x2, y2, id2] = vp[i + 1];
		if (x1 == x2 && y2 - y1 <= k)
			uf.Union(id1, id2);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		queue<pair<int, int>> q;
		map<pair<int, int>, int> mp;
		int n, k;
		scanf("%d%d", &n, &k);
		vector<tuple<int, int, int>> vp1, vp2;
		for (int i = 0; i < n; i++)
		{
			int x, y, t;
			scanf("%d%d%d", &x, &y, &t);
			vp1.emplace_back(x, y, i);
			vp2.emplace_back(y, x, i);
			a[i] = t;
		}
		uf.init(n);
		refrain(vp1, k);
		refrain(vp2, k);
		int l = 0, r = INF;
		int ans = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			fill(flag, flag + n, 0);
			for (int i = 0; i < n; i++)
			{
				if (a[i] <= mid) 
					flag[uf.Find(i)] = 1;
			}
			int rest = mid + 1;
			for (int i = 0; i < n; i++)
			{
				if (uf.Find(i) != i) continue;
				rest -= flag[i] ^ 1;
			}
			if (rest >= 0) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}