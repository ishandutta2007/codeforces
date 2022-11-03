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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 9;
const int N = 2e2 + 10;
vector<int> v[N];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
LL ansx[N], ansy[N];
void dfs(int x, int fa, LL d, LL cx, LL cy, int oo = -1)
{
	int o = 0;
	ansx[x] = cx;
	ansy[x] = cy;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		while (o == oo) o++;
		dfs(y, x, d / 3, cx + dx[o] * d, cy + dy[o] * d, o ^ 1);
		o++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL p = 1;
	for (int i = 0; i < 35; i++) p *= 3;
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() > 4)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	dfs(1, -1, p, 0, 0);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld %lld\n", ansx[i], ansy[i]);
	}
	return 0;
}