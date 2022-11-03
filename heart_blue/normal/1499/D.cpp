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
const int N = 2e7 + 10;
int p[N / 10];
int a[N];
void init()
{
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (a[i] == 0)
		{
			a[i] = 1;
			p[k++] = i;
		}
		for (int j = 0; j < k && p[j] * i < N; j++)
		{
			a[p[j] * i] = a[i] + 1;
			if (i % p[j] == 0)
			{
				a[p[j] * i]--;
				break;
			}
		}
	}
}
int solve(int c, int d, int x)
{
	int n = (x + d);
	if (n % c) return 0;
	n /= c;
	return 1 << a[n];
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
		int c, d, x;
		scanf("%d%d%d", &c, &d, &x);
		LL ans = 0;
		for (int i = 1; i * i <= x; i++)
		{
			if (x % i) continue;
			ans += solve(c, d, x / i);
			ans += solve(c, d, i);
			if (i * i == x)
				ans -= solve(c, d, i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}