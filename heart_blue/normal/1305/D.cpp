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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
set<int> v[N];
int fa[N];
void dfs(int x, int p = 0)
{
	fa[x] = p;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
void del(int x)
{
	int px = fa[x];
	v[x].erase(px);
	v[px].erase(x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].insert(y);
		v[y].insert(x);
	}
	int lca = 1;
	while(1)
	{
		int x = 0, y = 0;
		for (int i = 1; i <= n; i++)
		{
			if (v[i].size() == 1)
			{
				if (x == 0) x = i;
				else if (y == 0) y = i;
				else break;
			}
		}
		if (y == 0) break;
		cout << "? " << x << ' ' << y << endl;
		cin >> lca;
		if (lca == x || lca == y)
		{
			break;
		}
		dfs(lca);
		del(x);
		del(y);
	}
	cout << "! " << lca << endl;
	return 0;
}