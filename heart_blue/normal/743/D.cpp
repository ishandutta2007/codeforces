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
vector<int> vp[N];
LL w[N];
LL sum[N];
pair<int, int> check(pair<int, int> p1, pair<int, int> p2)
{
	int x, y;
	int a, b;
	tie(x, y) = p1;
	tie(a, b) = p2;
	if (y < a) swap(y, a);
	if (x < y) swap(x, y);
	if (y < b) swap(y, b);
	if (x < y) swap(x, y);
	return{ x,y };
}
LL dfs1(int x, int fa = -1)
{
	sum[x] = w[x];
	for (auto &y : vp[x])
	{
		if (y == fa) continue;
		sum[x] += dfs1(y, x);
	}
	return sum[x];
}
pair<LL, LL> dfs(int x, int fa = -1)
{
	LL ans = -INF*INF;
	LL a = ans, b = ans;
	int cnt = 0;
	for (auto &y : vp[x])
	{
		if (y == fa) continue;
		cnt++;
		auto tmp = dfs(y, x);
		ans = max(tmp.first, ans);
		if (b < tmp.second) b = tmp.second;
		if (a < b) swap(a, b);
	}
	if (cnt == 0) return{ ans, w[x] };
	if (b != -INF*INF) ans = max(ans, a + b);
	return{ ans, max(a,sum[x])};
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vp[x].push_back(y);
		vp[y].push_back(x);
	}
	dfs1(1);
	pair<LL, LL> ans = dfs(1);

	if (ans.first == -INF*INF) puts("Impossible");
	else cout << ans.first << endl;
	return 0;
}