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
	int minv[N];
	void init()
	{
		MEM(p, -1);
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
		minv[py] = minv[px] = min(minv[px], minv[py]);
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
map<string, int> ms;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, m;
	cin >> n >> k >> m;
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		ms[str] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> uf.minv[i];
	}
	while (k--)
	{
		int sz, x;
		cin >> sz >> x;
		sz--;
		while (sz--)
		{
			int y;
			cin >> y;
			if (uf.Find(x) != uf.Find(y))
			{
				uf.Union(x, y);
			}
		}
	}
	LL ans = 0;
	while (m--)
	{
		string str;
		cin >> str;
		int p = uf.Find(ms[str]);
		ans += uf.minv[p];
	}
	cout << ans << endl;
	return 0;
}