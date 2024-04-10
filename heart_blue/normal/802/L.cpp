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
vector<pair<int, int>> v[N];

LL powmod(LL a, LL b)
{
	a %= INF;
	if (a < 0) a += INF;
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % INF;
		b >>= 1;
		a = a * a % INF;
	}
	return ret;
}
pair<LL, LL> dfs(int x, int fa = -1)
{
	if (fa != -1 && v[x].size() == 1) return make_pair(0LL, 0LL);
	int sz = v[x].size();
	LL rev = powmod(sz, INF - 2);
	pair<LL, LL> ret = make_pair(0LL, 0LL);
	int fw = 0;
	for (auto& p : v[x])
	{
		int y, w;
		tie(y, w) = p;
		if (y == fa)
		{
			fw = w;
			continue;
		}
		auto pp = dfs(y, x);
		ret.first += pp.first * rev % INF;
		ret.second += (pp.second + w) * rev % INF;
	}
	ret.second += fw * rev % INF;
	ret.first %= INF;
	ret.second %= INF;
	if (x == 0) return ret;
	int o = powmod(1 - ret.first, INF - 2);
	ret = make_pair(rev * o % INF, ret.second * o % INF);
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		v[x].emplace_back(y, w);
		v[y].emplace_back(x, w);
	}
	auto ret = dfs(0);
	LL ans = ret.second * powmod(1 - ret.first, INF - 2) % INF;
	if (ans < 0) ans += INF;
	cout << ans << endl;
	return 0;
}