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
#include <regex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
const int MOD = 1E9 + 9;
LL a[N][N];
LL fact[N];
void init()
{
	for (int i = 0; i < N; i++) a[i][0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			if (a[i][j] >= MOD)
				a[i][j] -= MOD;
		}
	}
	fact[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fact[i] = fact[i - 1] * i % MOD;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	LL ans = 0;
	int n, w, b;
	scanf("%d%d%d", &n, &w, &b);
	for (int i = 1; i + 2 <= n; i++)
	{
		ans += a[n - i - 1][1] * a[b - 1][i - 1] % MOD * a[w - 1][n - i - 1] % MOD;
	}
	ans %= MOD;
	ans = ans * fact[w] % MOD * fact[b] % MOD;
	printf("%lld\n", ans);
	return 0;
}