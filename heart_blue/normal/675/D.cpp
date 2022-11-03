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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
pair<int,int> minv[N][20];
pair<int, int> a[N];
int ans[N];

pair<int,int> getmin(int x, int len)
{
	int o = 0;
	pair<int, int> ret = { 0x3f3f3f3f, 0x3f3f3f3f };
	while (len)
	{
		if (len & 1) ret = min(ret, minv[x][o]), x += 1 << o;
		o++;
		len >>= 1;
	}
	return ret;
}
void dfs(int l, int r, int fa)
{
	if (l > r) return;
	int pos = getmin(l, r - l + 1).second;
	ans[a[pos].second] = fa;
	dfs(l, pos - 1, a[pos].first);
	dfs(pos + 1, r, a[pos].first);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	MEM(minv, 0x3f);
	for (int i = 1; i <= n; i++)
	{
		minv[i][0] = { a[i].second, i };
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 1; j + (1 << i) <= n; j++)
		{
			minv[j][i + 1] = min(minv[j][i], minv[j + (1 << i)][i]);
		}
	}
	MEM(ans, -1);
	dfs(1, n, -1);
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == -1) continue;
		cout << ans[i] << ' ';
	}
	return 0;
}