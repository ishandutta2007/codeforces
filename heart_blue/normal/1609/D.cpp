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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
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
	int ans = 1;
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> vp(m);
	for (auto& [x, y] : vp)
		scanf("%d%d", &x, &y);
	for (int i = 0; i < m; i++)
	{
		uf.init();
		int cnt = 0;
		for (int j = 0; j <= i; j++)
		{
			auto [x, y] = vp[j];
			if (uf.Find(x) != uf.Find(y))
				uf.Union(x, y);
			else
				cnt++;
		}
		vector<int> v;
		for (int j = 1; j <= n; j++)
		{
			if (uf.Find(j) == j)
				v.push_back(uf.treesize(j));
		}
		sort(v.rbegin(), v.rend());
		while (v.size() > cnt + 1) v.pop_back();
		int ans = 0;
		for (auto& x : v)
			ans += x;
		printf("%d\n", ans - 1);
	}
	return 0;
}