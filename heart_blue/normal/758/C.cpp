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
const int N = 3e2 + 10;
LL a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, x, y;
	LL k;
	cin >> n >> m >> k >> x >> y;
	LL per = max(1, 2 * n - 2)*m;
	LL o = k / per;
	k %= per;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 || i == n) a[i][j] = o;
			else a[i][j] = o * 2;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (k > 0) a[i][j] ++, k--;
		}
	}
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			if (k > 0) a[i][j]++, k--;
		}
	}
	LL maxv = 0, minv = INF*INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			maxv = max(maxv, a[i][j]);
			minv = min(minv, a[i][j]);
		}
	}
	cout << maxv << ' ' << minv << ' ' << a[x][y] << endl;
	return 0;
}