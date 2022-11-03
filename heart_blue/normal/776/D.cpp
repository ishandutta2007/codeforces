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
const int N = 2e5 + 10;
vector<int> v[N], vp[N];
int flag[N];
int a[N];
bool dfs(int x, int o)
{
	if (flag[x] != -1)
	{
		return flag[x] == o;
	}
	flag[x] = o;
	for (auto &y : vp[x])
	{
		if (!dfs(y, o ^ 1)) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	MEM(flag, -1);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++)
	{
		int sz;
		cin >> sz;
		while (sz--)
		{
			int x;
			cin >> x;
			v[x].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		vp[i].push_back(i + m);
		vp[i + m].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		int x = v[i][0];
		int y = v[i][1];
		if (a[i])
		{
			vp[x].push_back(y + m);
			vp[y + m].push_back(x);
			vp[x + m].push_back(y);
			vp[y].push_back(x + m);
		}
		else
		{
			vp[x].push_back(y);
			vp[y].push_back(x);
			vp[x + m].push_back(y + m);
			vp[y + m].push_back(x + m);
		}
	}
	int ans = 1;
	for (int i = 1; i <= m; i++)
	{
		if (flag[i] != -1) continue;
		if (!dfs(i, 0)) ans = 0;
	}
	if (ans) puts("YES");
	else puts("NO");
	return 0;
}