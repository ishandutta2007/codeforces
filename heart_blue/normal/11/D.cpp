
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
const int N =1E6+ 10;
LL dp[N][19];
int lo[N];
int cnt[N];
int a[19][19];
int b[N];
vector<int> v[20];
LL ans[20];
void init()
{
	for (int i = 1; i < N; i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	for (int i = 1; i < N; i++)
	{
		if (i & 1) lo[i] = 0;
		else lo[i] = lo[i >> 1] + 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		a[x][y] = a[y][x] = 1;
	}
	for (int i = 0; i < n; i++) dp[1 << i][i] = 1;
	int tot = 1 << n;
	for (int o = 1; o < tot; o++)
	{
		int x = lo[o];
		for (int y = x; y < n; y++)
		{
			if (!(o >> y & 1)) continue;
			for (int z = x + 1; z < n; z++)
			{
				if (o >> z & 1) continue;
				if (a[y][z])
					dp[1 << z | o][z] += dp[o][y];
			}
		}
	}
	for (int i = 1; i < tot; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[lo[i]][j])
				ans[cnt[i]] += dp[i][j];
		}
	}
	LL res = 0;
	for (int i = 3; i <= n; i++)
		res += ans[i];
	printf("%lld\n", res / 2);

	return 0;
}