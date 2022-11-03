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
vector<int> v[N];
int sons[N];
int c[N];
int ans1 = 0, ans2 = 0;
void dfs(int x, int fa = 0)
{
	c[x] = c[fa] ^ 1;
	int cnt = 0;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		sons[x] += sons[y];
		if (sons[y] == 1)
			cnt++;
	}
	ans2 -= max(0, cnt - 1);
	sons[x]++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int key = 0;
	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() > 1)
		{
			key = i;
			break;
		}
	}
	ans1 = 1, ans2 = n - 1;
	dfs(key);
	int flag0 = 0, flag1 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() == 1)
		{
			if (c[i] == 0) flag0 = 1;
			if (c[i] == 1) flag1 = 1;
		}
	}
	if (flag0 && flag1)
		ans1 = 3;
	printf("%d %d\n", ans1, ans2);
	return 0;
}