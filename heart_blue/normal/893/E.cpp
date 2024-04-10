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
const int N = 1e6 + 10;
int dp[N][20];
LL fact[N];
LL rfact[N];
LL p2[N];
inline void add(int& x, int y)
{
	x += y;
	if (x >= INF)
		x -= y;
}
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = fact[i - 1] * i % INF;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++)
		rfact[i] = (INF - INF / i) * rfact[INF % i] % INF;
	for (int i = 2; i < N; i++)
		rfact[i] = rfact[i] * rfact[i - 1] % INF;
	p2[0] = 1;
	for (int i = 1; i < N; i++)
		p2[i] = p2[i - 1] * 2 % INF;
	dp[1][0] = 1;
	for (int o = 0; o + 1 < 20; o++)
	{
		for (int i = 1; i < N; i++)
		{
			if (dp[i][o] == 0) continue;
			int x = dp[i][o];
			for (int j = i + i; j < N; j += i)
			{
				add(dp[j][o + 1], x);
			}
		}
	}
}
LL C(int n, int m)
{
	return fact[n] * rfact[m] % INF * rfact[n - m] % INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		LL ans = 0;
		for (int i = 0; i < 20; i++)
		{
			if (i > m) break;
			ans += dp[n][i] * C(m, i);
		}
		ans %= INF;
		ans = ans * p2[m - 1] % INF;
		printf("%lld\n", ans);
	}
	return 0;
}