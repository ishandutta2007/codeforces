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
const int N = 1e6 + 10;
vector<pair<int, int>> vp;
int deg[N];
int flag[N];
int vis[N];
class UnionFind
{
private:
	int p[N];
public:
	int size(int x)
	{
		int px = Find(x);
		return -p[px];
	}
	void init()
	{
		MEM(p, -1);
	}
	int Find(int x)
	{
		int root = x;
		while (p[root] >= 0) root = p[root];
		while (x != root)
		{
			int tmp = p[x];
			p[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (size(px) > size(py)) swap(px, py);
		int total = size(px) + size(py);
		p[px] = py;
		p[py] = -total;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	uf.init();
	int cnt = 0;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		vis[x] = vis[y] = 1;
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
		}
		if (x != y)
		{
			deg[x]++;
			deg[y]++;
			vp.push_back({ x,y });
		}
		else flag[x] = 1, cnt++;
	}
	int tot = 0;
	for (int i = 1; i <= n; i++) tot += vis[i];
	if (uf.size(x) != tot)
	{
		cout << 0 << endl;
		return 0;
	}
	LL ans = 0;
	for (auto &p : vp)
	{
		ans += deg[p.first] + deg[p.second] - 2 + cnt;
	}
	ans += LL(m - 1)*cnt;
	cout << ans / 2 << endl;

	return 0;
}