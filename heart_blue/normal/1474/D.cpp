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
const int N = 2e5 + 10;
int lsum[N];
int rsum[N];
int a[N];
bool check(int x, int y, int z, int w)
{
	if (x == -1 || y == -1) return false;
	if (y < x) return false;
	y -= x;
	if (z < y) return false;
	z -= y;
	return z == w;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		fill(lsum + 1, lsum + n + 1, -1);
		fill(rsum + 1, rsum + n + 1, -1);
		rsum[n + 1] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (lsum[i - 1] == -1) lsum[i] = -1;
			else lsum[i] = max(-1, a[i] - lsum[i - 1]);
		}
		for (int i = n; i >= 1; i--)
		{
			if (rsum[i + 1] == -1) rsum[i] = -1;
			else rsum[i] = max(-1, a[i] - rsum[i + 1]);
		}
		if (lsum[n] == 0)
		{
			puts("YES");
			continue;
		}
		int flag = 0;
		for (int i = 1; i < n; i++)
		{
			if (check(lsum[i - 1], a[i + 1], a[i], rsum[i + 2]))
			{
				flag = 1;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}