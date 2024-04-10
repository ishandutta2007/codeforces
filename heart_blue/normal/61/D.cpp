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
vector<pair<int, int>> vp[N];
int depth[N];
void dfs(int x, int fa = -1)
{
	for (auto &p : vp[x])
	{
		int y, w;
		tie(y, w) = p;
		if (y == fa) continue;
		depth[y] = depth[x] + w;
		dfs(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	LL tot = 0;
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		vp[x].push_back({ y,w });
		vp[y].push_back({ x,w });
		tot += w;
	}
	depth[1] = 0;
	dfs(1);
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, depth[i]);
	cout << tot * 2 - ans << endl;
	return 0;
}