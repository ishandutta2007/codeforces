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
const int N = 1e5 + 10;
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
vector<int> vp[N];
pair<int, int> a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = i;
	sort(a + 1, a + n + 1);
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		if (a[i].second != i)
		{
			if (uf.Find(a[i].second) != uf.Find(i))
			{
				uf.Union(a[i].second, i);
			}
		}
	}
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		vp[uf.Find(i)].push_back(i);
		if (uf.Find(i) == i) k++;
	}
	cout << k << '\n';
	for (int i = 1; i <= n; i++)
	{
		if (vp[i].empty()) continue;
		cout << vp[i].size();
		for (auto &x : vp[i]) cout << ' ' << x;
		cout << '\n';
	}
	return 0;
}