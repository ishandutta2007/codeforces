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
const int N = 3e5 + 10;
int a[N];
int p[N];
int cnt[N * 100];
int k = 0;
void init()
{
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i + i; j < N; j += i)
		{
			a[j] = 1;
		}
		p[k++] = i;
	}
}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	scanf("%d", &n);
	int g = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		g = gcd(g, a[i]);
	}
	int tot = 0;
	int C = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == g) tot++;
		a[i] /= g;
		C = max(a[i], C);
	}
	if (tot == n)
	{
		puts("-1");
		return 0;;
	}
	for (int i = 1; i <= n; i++)
	{
		int x = a[i];
		for (int j = 0; p[j] * p[j] <= x; j++)
		{
			int o = p[j];
			if (x%o) continue;
			cnt[o]++;
			while (x%o == 0) x /= o;
		}
		if (x > 1) cnt[x]++;
	}
	int maxv = 0;
	for (int i = 1; i <= C; i++)
	{
		maxv = max(maxv, cnt[i]);
	}
	int ans = n - maxv;
	if (ans == n) ans = -1;
	printf("%d\n", ans);
	return 0;
}