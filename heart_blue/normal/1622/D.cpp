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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
const int MOD = 998244353;
int a[N][N];
int last[N];
int sum[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
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
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", str + 1);
	if (k == 0 || count(str + 1, str + n + 1, '1') < k)
	{
		puts("1");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + str[i] - '0';
	}
	int ptr = 1;
	for (int i = 1; i <= n; i++)
	{
		while (ptr <= n && sum[ptr] - sum[i - 1] <= k)
			ptr++;
		if (sum[ptr - 1] - sum[i - 1] == k)
		{
			for (int j = i; j < ptr; j++)
				last[j] = max(last[j], ptr - 1);
		}
	}
	LL ans = 1;
	for (int i = 1; i <= n; i++)
	{
		int j = last[i];
		int cnt1 = sum[j] - sum[i - 1];
		int cnt0 = (j - i + 1) - cnt1;
		if (str[i] == '0')
		{
			ans += a[cnt1 + cnt0 - 1][cnt0];
		}
		else
		{
			ans += a[cnt0 + cnt1 - 1][cnt1];
		}
	}
	ans %= MOD;
	printf("%lld\n", ans);
	return 0;
}