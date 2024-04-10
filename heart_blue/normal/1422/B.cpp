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
const int N = 2e2 + 10;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		LL ans = 0;
		for (int i = 1; i * 2 - 1 <= n; i++)
		{
			for (int j = 1; j * 2 - 1 <= m; j++)
			{
				vector<int> v;
				if (i * 2 - 1 == n && j * 2 - 1 == m) continue;
				if (i * 2 - 1 == n)
				{
					ans += abs(a[i][j] - a[i][m - j + 1]);
					continue;
				}
				if (j * 2 - 1 == m)
				{
					ans += abs(a[i][j] - a[n - i + 1][j]);
					continue;
				}
				v.push_back(a[i][j]);
				v.push_back(a[i][m - j + 1]);
				v.push_back(a[n - i + 1][j]);
				v.push_back(a[n - i + 1][m - j + 1]);
				sort(v.begin(), v.end());
				ans += 0LL + v[1] - v[0] + v[2] + v[3] - 2 * v[1];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}