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
int deg[N];
vector<int> v[N];
vector<pair<int, int>> vp, vd;
int flag[N];
map<pair<int, int>, int> mc;
void setvalue(int x, int y, int val)
{
	if (x > y) swap(x, y);
	mc[{x, y}] = val;
}
void dfs(int x, int o = 0, int p = 0)
{
	int cur = 0;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		if (flag[x])
		{
			setvalue(x, y, 1);
			dfs(y, 1, x);
		}
		else
		{
			cur++;
			if (cur == o) cur++;
			setvalue(x, y, cur);
			dfs(y, cur, x);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		vp.emplace_back(x, y);
		v[x].push_back(y);
		v[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		vd.emplace_back(deg[i], i);
	}
	sort(vd.rbegin(), vd.rend());
	for (int i = 0; i < k; i++)
	{
		flag[vd[i].second] = 1;
	}
	dfs(1);
	int maxv = vd[k].first;
	printf("%d\n", maxv);
	for (auto &p : vp)
	{
		printf("%d ", mc[p]);
	}
	return 0;
}