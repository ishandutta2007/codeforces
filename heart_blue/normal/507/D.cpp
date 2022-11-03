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
const int N = 1e3 + 10;
int dp[N][110][2];
LL cnt[N];
LL p[N];
void init(int m, int k)
{
	LL lo = 1;
	LL up = 9;
	cnt[0] = 1;
	for (int i = 1; i < N; i++)
	{
		cnt[i] = (up - lo + 1) % m;
		if (cnt[i] < 0) cnt[i] += m;
		lo = lo * 10 % m;
		up = (up * 10 + 9) % m;
	}
	p[1] = 1 % k;
	for (int i = 2; i < N; i++)
	{
		p[i] = p[i - 1] * 10 % k;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, m;
	cin >> n >> k >> m;
	init(m, k);
	LL ans = 0;
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i % k][i != 0]++;
	}
	for (int i = 1; i <= n; i++)
	{
		ans += dp[i][0][1] * cnt[n - i] % m;
		if (i == n) break;
		dp[i][0][0] = 1;
		dp[i][0][1] = 0;
		for (int j = 0; j < k; j++)
		{
			for (int o = 0; o < 2; o++)
			{
				if (dp[i][j][o] == 0) continue;
				for (int t = 0; t < 10; t++)
				{
					int x = (j + t * p[i + 1]) % k;
					int& tmp = dp[i + 1][x][t != 0] += dp[i][j][o];
					if (tmp >= m)
						tmp -= m;
				}
			}
		}
	}
	cout << ans % m << endl;
	return 0;
}