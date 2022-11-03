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
const int N = 5e2 + 10;
int sum[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<tuple<int, int, int>> vp;
	int n, m, k, q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	while (q--)
	{
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		vp.emplace_back(x, y, t);
	}
	int l = 0, r = INF;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		MEM(sum, 0);
		for (auto& p : vp)
		{
			int x, y, t;
			tie(x, y, t) = p;
			if (t <= mid)
			{
				sum[x][y] = 1;
			}
		}
		int flag = 0;
		for (int i = 1; i <= n && flag == 0; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
				if (i >= k && j >= k && sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k] == k * k)
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}