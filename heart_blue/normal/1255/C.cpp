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
vector<int> vp[N];
map<pair<int, int>, vector<int>> mc;
vector<int> v[N];
int deg[N];
int ans[N];
int sub(vector<int>& v1, vector<int>& v2)
{
	int ret = 0;
	for (auto& x : v1)
	{
		ret = x;
		for (auto& y : v2)
		{
			if (x == y) ret = 0;
		}
		if (ret) break;
	}
	return ret;
}
void dfs(int x, int fa = 0, int cur = 1)
{
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		ans[cur] = sub(vp[x], vp[y]);
		ans[cur + 3] = sub(vp[y], vp[x]);
		dfs(y, x, cur + 1);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n - 2; i++)
	{
		int cnt = 3;
		while (cnt--)
		{
			int x;
			cin >> x;
			vp[i].push_back(x);
		}
		sort(vp[i].begin(), vp[i].end());
		for (int k = 0; k < 3; k++)
		{
			for (int j = k + 1; j < 3; j++)
			{
				mc[make_pair(vp[i][k], vp[i][j])].push_back(i);
			}
		}
	}
	for (auto& p : mc)
	{
		vector<int>& vv = p.second;
		if (vv.size() != 2) continue;
		int x = vv[0], y = vv[1];
		v[x].push_back(y);
		v[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}
	int rt = find(deg + 1, deg + (n - 2) + 1, 1) - deg;
	dfs(rt);
	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(i);
	for (int i = 1; i <= n; i++)
	{
		s.erase(ans[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 0)
			ans[i] = *s.begin();
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	return 0;
}