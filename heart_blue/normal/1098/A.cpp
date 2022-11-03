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
vector<int> v[N];
int val[N];
int a[N];
void dfs(int x, int fa = 0)
{
	if (v[x].empty())
	{
		val[x] = max(val[x], val[fa]);
		a[x] = val[x] - val[fa];
		if (a[x] < 0) puts("-1"), exit(0);
		return;
	}
	if (val[x] == -1)
	{
		int maxv = INF;
		for (auto& y : v[x])
		{
			maxv = min(maxv, val[y] - val[fa]);
		}
		if (maxv < 0) puts("-1"), exit(0);
		val[x] = maxv + val[fa];
	}
	a[x] = val[x] - val[fa];
	for (auto& y : v[x])
	{
		dfs(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int fa;
		cin >> fa;
		v[fa].push_back(i);
	}
	for (int i = 1; i <= n; i++) cin >> val[i];
	dfs(1);
	LL ans = 0;
	for (int i = 1; i <= n; i++) ans += a[i];
	cout << ans << endl;
	return 0;
}