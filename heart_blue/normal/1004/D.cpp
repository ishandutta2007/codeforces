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
int a[N];
int cnt[N];
int cnt2[N];
int maxv = 0;
bool check(int n, int m, int x, int y)
{
	if (x < 1 || x > n) return false;
	if (y < 1 || y > m) return false;
	MEM(cnt2, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int o = abs(i - x) + abs(j - y);
			if (cnt2[o]++ == cnt[o]) return false;
		}
	}
	printf("%d %d\n", n, m);
	printf("%d %d\n", x, y);
	return true;
}
bool check(int n, int m, int o)
{
	int x = o;
	int y = n - x + m - maxv;
	return check(n, m, x, y) || check(n, m, y, x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &a[i]); cnt[a[i]]++;
		maxv = max(maxv, a[i]);
	}
	if (cnt[0] != 1)
	{
		puts("-1");
		return 0;
	}
	int o = 1;
	for (int i = 1; i < t; i++)
	{
		if (cnt[i] != 4 * i)
		{
			o = i;
			break;
		}
	}
	for (int i = 1; i * i <= t; i++)
	{
		if (t%i) continue;
		if (check(i, t / i, o))
		{
			return 0;
		}
	}
	puts("-1");
	return 0;
}