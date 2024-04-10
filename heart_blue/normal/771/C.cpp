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
const int N = 2e5 + 10;
vector<int> v[N];
LL dp[N][2][5];
int n, k;
LL ans = 0;
LL tot = 0;
void dfs(int x, int fa = -1)
{
	LL *a = dp[x][0];
	LL *b = dp[x][1];
	b[0] = 1;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (b[i] > 0 && dp[y][1][j] > 0)
					ans += dp[y][1][j] * a[i] + b[i] * dp[y][0][j] + (i + j + 1 >= k)*b[i] * dp[y][1][j];
				if ((i + j + 1) % k == 0) tot += b[i] * dp[y][1][j];
			}
		}
		for (int i = 0; i < k; i++)
		{
			a[(i + 1) % k] += dp[y][0][i] + (i + 1 == k)*dp[y][1][i];
			b[(i + 1) % k] += dp[y][1][i];
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cout << ans + LL(n)*(n - 1) / 2 - tot << endl;
	return 0;
}