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
const int N = 2e6 + 10;
int a[N];
int d[N];
int prime[N];
int key[N];
int cnt[N];
int cnt2[N];
int k = 0;
inline void init()
{
	for (int i = 2; i < N; i++)
	{
		if (!a[i])
			prime[++k] = i, d[i] = i;
		for (int j = 1; j <= k && (LL)i*prime[j] < N; j++)
		{
			d[i*prime[j]] = prime[j];
			a[i*prime[j]] = 1;
			if (i%prime[j] == 0)
				break;
		}
	}
	for (int i = 2; i < N; i++)
	{
		if (i / d[i] % d[i] == 0) key[i] = d[i] * key[i / d[i]];
		else key[i] = d[i];
	}
}

bool check(int x, int o = 0)
{
	int tot = 0;
	int cnt = 0;
	while (x > 1)
	{
		tot++;
		cnt += cnt2[key[x]] > 0;
		cnt2[key[x]] += o;
		x /= key[x];
	}
	return tot = cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	int ok = 0;
	for (int i = k; i > 0; i--)
	{
		int p = prime[i];
		if (cnt[p])
		{
			if (!check(p, 0))
			{
				check(p, 1), cnt[p]--;
			}
		}
		if (cnt[p] > 1) ok = 1;
		else if (p == 2 && cnt[p] > 0) ok = 1;
		if (cnt[p]) check(p - 1, 1);
	}
	for (int i = N - 1; i > 1; i--)
	{
		if (cnt2[i] <= 0)
		{
			continue;
		}
		int x = i;
		int sum = -cnt2[i];
		while (x > 1)
		{
			x /= d[x];
			cnt2[x] = -2;
		}
	}
	for (int i = 1; i <= k && !ok; i++)
	{
		int p = prime[i];
		if (cnt[p] == 0) continue;
		int cnt = 0;
		int tot = 0;
		int x = p - 1;
		while (x > 1)
		{
			tot++;
			if (cnt2[key[x]] != 1) cnt++;
			x /= key[x];
		}
		if (cnt == tot) ok = 1;
	}
	LL ans = 1;
	for (int i = N - 1; i > 1; i--)
	{
		if (cnt2[i] <= 0) continue;
		ans = ans * i%INF;
	}
	if (ok) ans++;
	if (ans >= INF) ans -= INF;
	printf("%lld\n", ans);
	return 0;
}