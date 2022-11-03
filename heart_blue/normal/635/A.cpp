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
const int N = 3e2 + 10;
int sum[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(sum, 0);
	int r, c, n, k;
	cin >> r >> c >> n >> k;
	while (n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		sum[x][y] = 1;
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	}
	int ans = 0;
	for (int r1 = 1; r1 <= r; r1++)
	{
		for (int r2 = r1; r2 <= r; r2++)
		{
			for (int c1 = 1; c1 <= c; c1++)
			{
				for (int c2 = c1; c2 <= c; c2++)
				{
					if (sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1] >= k)
					{
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}