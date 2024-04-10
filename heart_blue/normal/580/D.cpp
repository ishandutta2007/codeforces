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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 20;
int a[N][N];
LL dp[1 << N][N];
LL b[1 << N];
int cnt[1 << N];
void init(int n)
{
	b[0] = cnt[0] = 0;
	for (int i = 1; i < (1 << n); i++)
	{
		b[i] = b[i - (i&-i)] + b[i&-i];
		cnt[i] = cnt[i - (i&-i)] + 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	MEM(b, 0);
	cin >> n >> m >> k;
	LL ans = 0;
	MEM(a, 0);
	MEM(dp, 0);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		b[1 << i] = x;
	}
	init(n);
	while (k--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		a[x][y] = w;
	}
	for (int i = 1; i < (1 << n); i++)
	{
		if (i == (i&-i)) continue;
		if (cnt[i] > m) continue;
		for (int o1 = 0; o1 < n; o1++)
		{
			if ((1 << o1)&i)
			{
				for (int o2 = 0; o2 < n; o2++)
				{
					if ((1 << o2)&i)
					{
						dp[i][o1] = max(dp[i][o1], dp[i ^ (1 << o1)][o2] + a[o2][o1]);
					}
				}
			}
		}
	}
	for (int i = 1; i < (1 << n); i++)
	{
		if (cnt[i] == m)
		{
			for (int j = 0; j < n; j++)
			{
				ans = max(ans, b[i] + dp[i][j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}