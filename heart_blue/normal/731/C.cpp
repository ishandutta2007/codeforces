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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

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
vector<int> v[N];
int cnt[N];
int flag[N];
int col[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int n, m;
	scanf("%d%d%*d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &col[i]);
	MEM(flag, 0);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (uf.Find(x) != uf.Find(y)) uf.Union(x, y);
	}
	for (int i = 1; i <= n; i++) v[uf.Find(i)].push_back(col[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int maxv = 0;
		for (auto &x : v[i])
		{
			if (flag[x] != i) flag[x] = i, cnt[x] = 0;
			cnt[x] ++;
			maxv = max(maxv, cnt[x]);
		}
		ans += v[i].size() - maxv;
	}
	cout << ans << endl;
	return 0;
}