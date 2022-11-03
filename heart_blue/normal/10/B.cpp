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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int sum[N][N];
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int mid = (k + 1) / 2;
	while (n--)
	{
		int sz;
		cin >> sz;
		tuple<int, int, int> ans = { int(INF),-1,-1 };
		for (int i = 1; i <= k; i++)
		{
			for (int j = sz; j <= k; j++)
			{
				if (sum[i][j] != sum[i][j - sz]) continue;
				int tot = abs(i - mid) * sz;
				for (int o = 0; o < sz; o++)
				{
					tot += abs(j - o - mid);
				}
				ans = min(ans, make_tuple(tot, i, j - sz + 1));
			}
		}
		int tot, x, y;
		tie(tot, x, y) = ans;
		if (tot == INF) puts("-1");
		else
		{
			printf("%d %d %d\n", x, y, y + sz - 1);
			for (int i = 0; i < sz; i++) flag[x][y + i] = 1;
			for (int i = 1; i <= k; i++)
			{
				sum[x][i] = sum[x][i - 1] + flag[x][i];
			}
		}
	}
	return 0;
}