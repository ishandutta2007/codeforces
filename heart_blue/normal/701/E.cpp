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
int n, k;
int sons[N];
vector<int> v[N];
int flag[N];
LL ans = 0;
void dfs(int x, int fa = -1)
{
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		ans += min(sons[y], 2 * k - sons[y]);
		sons[x] += sons[y];
	}
	sons[x] += flag[x];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < 2 * k; i++)
	{
		int x;
		cin >> x;
		flag[x] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}