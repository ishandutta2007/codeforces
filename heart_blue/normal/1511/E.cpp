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
const int N = 3e5 + 10;
const LL mod = 998244353;
string vs[N + 10];
int cnt[N + 10];
int sum[N + 10];
LL p2[N + 10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	p2[0] = 1;
	for (int i = 1; i < N; i++)
		p2[i] = p2[i - 1] * 2 % mod;
	scanf("%d%d", &n, &m);
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> vs[i];
		int cur = 0;
		for (int j = 0; j < m; j++)
		{
			if (vs[i][j] == 'o') cur++, tot++;
			else
			{
				cnt[cur]++;
				cur = 0;

			}
		}
		cnt[cur]++;
	}
	for (int j = 0; j < m; j++)
	{
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			if (vs[i][j] == 'o') cur++;
			else
			{
				cnt[cur]++;
				cur = 0;
			}
		}
		cnt[cur]++;
	}
	for (int i = N - 2; i >= 0; i--)
	{
		sum[i] = sum[i + 1] + cnt[i];
	}
	LL ans = 0;
	for (int i = 2; i + 1 <= tot; i++)
	{
		ans += sum[i + 1] * 2 * p2[tot - i - 1] % mod * (i / 2) % mod;
	}
	for (int i = N - 2; i >= 0; i--)
	{
		sum[i] += sum[i + 1];
	}
	for (int i = 2; i + 2 <= tot; i++)
	{
		ans += sum[i + 2] * p2[tot - i - 2] % mod * (i / 2) % mod;
	}
	for (int i = 2; i <= tot; i++)
	{
		ans += cnt[i] * p2[tot - i] % mod * (i / 2) % mod;
	}
	printf("%lld\n", ans % mod);
	return 0;
}