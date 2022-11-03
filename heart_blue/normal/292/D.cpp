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
pair<int, int> p[N];
class UnionFind
{
	int p[N];
public:
	void init(int n = N)
	{
		memset(p, -1, sizeof(int)*n);
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
int res[N];
vector<pair<int, int>> vp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int lo = n;
	uf.init(n + 1);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &p[i].first, &p[i].second);
		if (uf.Find(p[i].first) != uf.Find(p[i].second))
			uf.Union(p[i].first, p[i].second), lo--;
	}

	int q;
	scanf("%d", &q);
	for(int i =1; i <= q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		vp[l].push_back({ r,i });
	}
	for (int i = 1; i <= m; i++)
	{
		if (vp[i].empty()) continue;
		uf.init(n + 1);
		sort(vp[i].begin(), vp[i].end());
		int ans = n;
		for (int j = 1; j < i; j++)
		{
			int x, y;
			tie(x, y) = p[j];
			if (uf.Find(x) != uf.Find(y))
				uf.Union(x, y), ans--;
		}
		int cur = m;
		while (!vp[i].empty())
		{
			int r, pos;
			tie(r, pos) = vp[i].back();
			vp[i].pop_back();
			while (cur > r && ans != lo)
			{
				if (uf.Find(p[cur].first) != uf.Find(p[cur].second))
					uf.Union(p[cur].first, p[cur].second), ans--;
				cur--;
			}
			res[pos] = ans;
		}
	}
	for (int i = 1; i <= q; i++) printf("%d\n", res[i]);
	return 0;
}