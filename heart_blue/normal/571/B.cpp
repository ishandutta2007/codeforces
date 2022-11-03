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
const int N = 5e3 + 10;
int a[300000 + 100];
LL dp[N][N];
int sz1, sz2;
LL dfs(int x, int y)
{
	if (x < 0 || y < 0)
	{
		return INF*INF;
	}
	if (dp[x][y] != -1) return dp[x][y];
	int cur = x*sz1 + y*sz2;
	dp[x][y] = min(dfs(x, y - 1) + a[cur] - a[cur - sz2 + 1],
		dfs(x - 1, y) + a[cur] - a[cur - sz1 + 1]);
	return dp[x][y];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	MEM(dp, -1);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	sz1 = n / k, sz2 = n / k + 1;
	cout << dfs(k - n%k, n%k) << endl;
	return 0;
}