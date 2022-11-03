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
class UnionSet
{
public:
	int fa[N];
	void init()
	{
		MEM(fa, -1);
	}
	int treesize(int x)
	{
		return -fa[Find(x)];
	}
	int Find(int x)
	{
		int root = x;
		while (fa[root] >= 0) root = fa[root];
		while (x != root)
		{
			int tmp = fa[x];
			fa[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
	}
} uf;
vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	uf.init();
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
		}
		else
		{
			vp.push_back({ x,y });
		}
	}
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		if (i == uf.Find(i))
			v.push_back(i);
	}
	cout << vp.size() << endl;
	for (int i = 0; i < vp.size(); i++)
	{
		cout << vp[i].first << ' ' << vp[i].second << ' ';
		cout << v[0] << ' ' << v[i + 1] << endl;
	}
	return 0;
}