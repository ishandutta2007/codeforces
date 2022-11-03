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
const int N = 1e5 + 10;
vector<pair<int,int>> v[N];
int sz;
int vis[N];
void dfs(int x, int fa = -1)
{
	vis[x] = 1;
	sz++;
	for (auto &p : v[x])
	{
		int y, w;
		tie(y, w) = p;
		if (y == fa) continue;
		if (w == 1) continue;
		dfs(y, x);
	}
}
int check(int x)
{
	while (x)
	{
		if (x % 10 != 4 && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
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
		w = check(w);
		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		sz = 0;
		dfs(i);
		ans += 1LL * sz*(n - sz)*(n - sz - 1);
	}
	cout << ans << endl;
	return 0;
}