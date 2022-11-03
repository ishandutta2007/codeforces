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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1.2e6 + 10;
int a[N];
int cnt[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i < N; i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	scanf("%s", str);
	for (int i = 0; str[i]; i++)
	{
		int o = 0;
		for (int j = i; str[j]; j++)
		{
			int x = str[j] - 'a';
			if (o >> x & 1) break;
			o |= 1 << x;
			a[o] = cnt[o];
		}
	}
	int tot = 1 << 20;
	for (int i = 1; i < tot; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (i >> j & 1)
			{
				a[i] = max(a[i], a[i ^ (1 << j)]);
			}
		}
	}
	int mask = tot - 1;
	int ans = a[mask];
	for (int o = 1; o < tot; o++)
	{
		if (a[o] != cnt[o]) continue;
		ans = max(ans, a[o] + a[o ^ mask]);
	}
	printf("%d\n", ans);
	return 0;
}