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
const int N = 7e1 + 10;
int dp[N][N][N];
int pre[N][N][N];
int n;
char str[N][N];
int inf;
void build()
{
	MEM(dp, 0x3f);
	inf = dp[0][0][0];
	queue<tuple<int, int, int>> q;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	do
	{
		int x = v[0];
		int y = v[1];
		int z = v[2];
		dp[x][y][z] = 0;
		q.emplace(x, y, z);
	} while (next_permutation(v.begin(), v.end()));
	while (!q.empty())
	{
		auto [x, y, z] = q.front();
		q.pop();
		int cur = dp[x][y][z] + 1;
		for (int i = 1; i <= n; i++)
		{
			if (i == x || i == y || i == z) continue;
			if (str[y][z] == str[x][i] && dp[i][y][z] > cur)
				dp[i][y][z] = cur, pre[i][y][z] = x << 2, q.emplace(i, y, z);
			if (str[x][z] == str[y][i] && dp[x][i][z] > cur)
				dp[x][i][z] = cur, pre[x][i][z] = y << 2 | 1, q.emplace(x, i, z);
			if (str[x][y] == str[z][i] && dp[x][y][i] > cur)
				dp[x][y][i] = cur, pre[x][y][i] = z << 2 | 2, q.emplace(x, y, i);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	build();
	int ret = dp[x][y][z];
	if (ret == inf) puts("-1"), exit(0);
	printf("%d\n", ret);
	while (x + y + z != 6)
	{
		int key = pre[x][y][z];
		int a[4] = { x,y,z };
		int o = key & 3;
		key >>= 2;
		printf("%d %d\n", a[o], key);
		a[o] = key;
		x = a[0], y = a[1], z = a[2];
	}
	return 0;
}