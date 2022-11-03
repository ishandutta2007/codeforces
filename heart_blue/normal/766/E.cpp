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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> vp[N];
int a[N];
int sum[N][2];
LL cnt = 0;
void dfs(int x, int pos, int fa = 0)
{
	int o = a[x] >> pos & 1;
	sum[x][0] = sum[x][1] = 0;
	sum[x][o] = 1;
	cnt += o;
	for (auto& y : vp[x])
	{
		if (y == fa) continue;
		dfs(y, pos, x);
		cnt += 1LL * sum[x][1] * sum[y][0] + 1LL * sum[x][0] * sum[y][1];
		sum[x][0 ^ o] += sum[y][0];
		sum[x][1 ^ o] += sum[y][1];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp[x].push_back(y);
		vp[y].push_back(x);
	}
	LL ans = 0;
	for (int pos = 0; pos <= 20; pos++)
	{
		cnt = 0;
		dfs(1, pos);
		ans += cnt << pos;
	}
	printf("%lld\n", ans);
	return 0;
}