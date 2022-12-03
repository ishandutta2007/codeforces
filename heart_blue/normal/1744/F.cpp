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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int pos[N];
LL sum(LL a, LL b)
{
	if (a > b) swap(a, b);
	return (a + b) * (b - a + 1) / 2;
}
LL check(int x, int y, int len)
{
	if (len < 0) return 0;
	x = min(x, len);
	y = min(y, len);
	len = min(len, x + y);
	if (x > y) swap(x, y);
	return sum(len - x + 1, y + 1) + 1LL * (y + 1) * (len - y);
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
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			pos[x] = i;
		}
		int l = INF, r = 0;
		LL ans = 0;
		for (int i = 0; i < n; i++)
		{
			l = min(l, pos[i]);
			r = max(r, pos[i]);
			while (i + 1 < n && l <= pos[i + 1] && pos[i + 1] <= r)
			{
				i++;
			}
			if (i == n - 1)
			{
				ans++;
				break;
			}
			int mex = i + 1;
			int L = 1, R = n;
			if (pos[i + 1] < l) L = pos[i + 1] + 1;
			else R = pos[i + 1] - 1;
			ans += check(l - L, R - r, i * 2 + 1 - (r - l));
		}
		printf("%lld\n", ans);
	}
	return 0;
}