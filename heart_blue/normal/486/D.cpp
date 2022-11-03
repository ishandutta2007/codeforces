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
const int N = 2e3 + 10;
int n, d;
vector<int> v[N];
pair<int, int> w[N];
LL dfs(int x, int cur, int fa = -1)
{
	if (w[x] < w[cur]) return 0;
	if (w[x].first - w[cur].first > d) return 0;
	LL ans = 1;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		ans = ans * (dfs(y, cur, x) + 1) % INF;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> d >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i].first;
		w[i].second = i;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++) ans += dfs(i, i);
	cout << ans % INF << endl;
	return 0;
}