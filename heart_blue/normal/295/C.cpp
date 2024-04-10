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
const int N = 5e1 + 10;
int dp[N][N][2];
int cnt[N][N][2];
int c[N][N];
void init()
{
	for (int i = 0; i < N; i++) c[i][0] = c[i][i] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= INF) c[i][j] -= INF;
		}
	}

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	int n, k;
	init();
	cin >> n >> k;
	a = 0, b = 0;
	k /= 50;
	while (n--)
	{
		int x;
		cin >> x;
		if (x == 50) a++;
		else b++;
	}
	MEM(dp, 0x3f);
	MEM(cnt, 0);
	dp[a][b][0] = 1;
	cnt[a][b][0] = 1;
	queue<tuple<int, int, int>> q;
	q.emplace(a, b, 0);
	while (!q.empty())
	{
		int x, y, o;
		tie(x, y, o) = q.front();
		q.pop();
		for (int i = 0; i <= x; i++)
		{
			for (int j = 0; j <= y; j++)
			{
				if (i == x && j == y) continue;
				if ((x - i) + (y - j) * 2 > k) continue;
				if (dp[a - i][b - j][o ^ 1] > dp[x][y][o] + 1)
				{
					dp[a - i][b - j][o ^ 1] = dp[x][y][o] + 1;
					q.emplace(a - i, b - j, o ^ 1);
				}
				if (dp[a - i][b - j][o ^ 1] == dp[x][y][o] + 1)
				{
					int& tmp = cnt[a - i][b - j][o ^ 1];
					tmp = (tmp + cnt[x][y][o] * 1LL * c[x][i] % INF * c[y][j]) % INF;
				}
			}
		}
	}
	if (dp[a][b][1] == 0x3f3f3f3f) puts("-1\n0");
	else printf("%d\n%d\n", dp[a][b][1] - 1, cnt[a][b][1]);
	return 0;
}