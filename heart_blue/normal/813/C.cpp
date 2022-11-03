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
int *dis;
int dis1[N], dis2[N];
vector<int> v[N];
void dfs(int x, int fa = -1)
{
	dis[x] = 0;
	if (fa != -1) dis[x] = dis[fa] + 1;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n >> x;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dis = dis1;
	dfs(1);
	dis = dis2;
	dfs(x);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dis2[i] < dis1[i]) ans = max(ans, dis1[i] * 2);
	}
	cout << ans << endl;
	return 0;
}