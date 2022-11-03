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
class UnionFind
{
	int p[N];
public:
	void init(int n = N)
	{
		memset(p, -1, sizeof(int)*N);
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
		while (x != s)
		{
			int tmp = p[x];
			p[x] = s;
			x = tmp;
		}
		return s;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (p[px] < p[py]) swap(px, py);
		p[py] += p[px];
		p[px] = py;
	}
} uf;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	uf.init();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (k--)
	{
		int x, y;
		cin >> x >> y;
		if (uf.Find(x) != uf.Find(y)) uf.Union(x, y);
	}
	for (int i = 1; i <= n; i++)
	{
		int p = uf.Find(i);
		a[p] = min(a[p], a[i]);
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int p = uf.Find(i);
		ans += a[p];
		a[p] = 0;
	}
	cout << ans << endl;

	return 0;
}