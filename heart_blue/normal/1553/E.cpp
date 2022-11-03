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
const int N = 3e5 + 10;
vector<int> v[N];
int a[N]; 
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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			v[i].clear();
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			a[i] = x;
			x = i - x;
			if (x < 0) x += n;
			v[x].push_back(i);
		}
		vector<int> ans;
		for (int i = 0; i < n; i++)
		{
			if (v[i].size() < n - 2 * m) continue;
			uf.init(n + 1);
			for (int j = 1; j <= n; j++)
			{
				int x = j - i;
				if (x <= 0) x += n;
				int y = a[j];
				if (uf.Find(x) != uf.Find(y))
					uf.Union(x, y);
			}
			int tot = 0;
			for (int j = 1; j <= n; j++)
			{
				if (uf.Find(j) != j) continue;
				tot += uf.treesize(j) - 1;
			}
			if (tot <= m)
				ans.push_back(i);
		}
		printf("%d", ans.size());
		for (int i = 0; i < ans.size(); i++)
		{
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}