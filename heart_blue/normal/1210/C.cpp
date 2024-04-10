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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
LL w[N];
vector<int> v[N];
LL ans = 0;
void dfs(int x, vector<pair<LL, int>>& s, int fa = 0, int depth = 1)
{
	vector<pair<LL, int>> vp;
	ans += w[x];
	for (auto [w2, pos] : s)
	{
		LL g = gcd(w[x], w2);
		if (vp.empty() || vp.back().first != g)
			vp.emplace_back(g, pos);
	}
	vp.emplace_back(w[x], depth);
	for (int i = 0; i + 1 < vp.size(); i++)
	{
		ans += (vp[i + 1].second - vp[i].second) * vp[i].first % INF;
	}
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs(y, vp, x, depth + 1);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<pair<LL, int>> vp;
	dfs(1, vp);
	printf("%lld\n", ans % INF);
	return 0;
}