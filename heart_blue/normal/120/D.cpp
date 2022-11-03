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
const int N = 1e2 + 10;
int a[N][N], b[N][N];
int sum[N];
int x, y, z;
void refrain(int &x, int &y, int &z)
{
	if (x > y) swap(x, y);
	if (y > z) swap(y, z);
	if (x > y) swap(x, y);
}
int solve(int n, int m)
{
	MEM(sum, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum[j] += a[i][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		sum[i] += sum[i - 1];
	}
	int ret = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			int X = sum[i], Y = sum[j] - sum[i], Z = sum[m] - sum[j];
			refrain(X, Y, Z);
			if (x == X && y == Y && z == Z)
			{
				ret++;
			}
		}
	}
	return ret;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}
	cin >> x >> y >> z;
	refrain(x, y, z);
	int ans = solve(n, m);
	memcpy(a, b, sizeof(a));
	ans += solve(m, n);
	cout << ans << endl;
	return 0;
}