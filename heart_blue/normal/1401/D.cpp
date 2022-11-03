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
vector<LL> v1, v2;
vector<int> v[N];
int n;
int sz[N];
void dfs(int x, int p = 0)
{
	sz[x] = 1;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
		sz[x] += sz[y];
		v1.push_back(1LL * (n - sz[y]) * sz[y]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int m;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) v[i].clear();
		v1.clear(), v2.clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1);
		sort(v1.begin(), v1.end());
		scanf("%d", &m);
		v2.resize(m);
		for (auto& x : v2) scanf("%lld", &x);
		while (v2.size() < n - 1) v2.push_back(1);
		sort(v2.begin(), v2.end());
		while (v2.size() > n - 1)
		{
			LL x = v2.back();
			v2.pop_back();
			v2.back() = (v2.back() * x) % INF;
		}
		LL ans = 0;
		for (int i = 0; i < v1.size(); i++)
		{
			ans += v1[i] % INF * v2[i] % INF;
		}
		printf("%lld\n", ans % INF);
	}
	return 0;
}