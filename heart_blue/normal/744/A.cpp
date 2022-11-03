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
const int N = 1e3 + 10;
int a[N][N];
int vis[N];
int flag[N];
int n, m, k;
int cnt[N];
void dfs(int x, int cur)
{
	if (vis[x]) return;
	vis[x] = cur;
	for (int i = 1; i <= n; i++)
	{
		if (a[x][i])
			dfs(i, cur);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	int x, y;
	MEM(flag, 0);
	MEM(vis, 0);
	MEM(a, 0);
	MEM(cnt, 0);
	while (k--)
	{
		cin >> x;
		flag[x] = 1;
	}
	int ans = -m;
	while (m--)
	{
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (flag[i])
			dfs(i, i);
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			dfs(i, i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[vis[i]]) cnt[vis[i]]++;
		else cnt[0]++;
	}
	sort(cnt + 1, cnt + n + 1);
	cnt[n] += cnt[0];
	for (int i = 1; i <= n; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}