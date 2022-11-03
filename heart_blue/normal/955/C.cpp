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
const LL inf = 4 * INF * INF;
const int N = 1e5 + 10;
LL key[100];
int mu[] = {
	0,1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1, 1, -1, 0, 0, 1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, 1, 1, 0, -1, -1, -1, 0, 0, 1, -1, 0, 0, 0, 1, 0, -1, 0, 1, 0, 1, 1, -1, 0, -1, 1, 0, 0, 1, -1, -1, 0, 1, -1, -1, 0, -1, 1, 0, 0, 1, -1
};
inline LL powfun(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a;
		a = a * a;
		b >>= 1;

	}
	return ret;
}
LL check(LL x, LL b)
{
	LL l = 1, r = key[b];
	LL ret = 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (powfun(mid, b) <= x) ret = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ret - 1;
}
LL solve(LL x)
{
	if (x == 0) return 0;
	if (x == 1) return 1;
	LL ret = x - 1;
	for (int i = 2; i <= 64; i++)
	{
		int tot = check(x, i);
		if (tot == 0) break;
		ret += mu[i] * tot;
	}
	return x - ret;
}
void init()
{
	for (int b = 2; b <= 64; b++)
	{
		LL x = 1e18;
		LL t = pow(x, 1.0 / b) + 1;
		while (1)
		{
			LL tot = 1;
			for (int i = 1; i <= b; i++)
			{
				if (tot > x / t)
				{
					tot = -1;
					break;
				}
				tot *= t;
			}
			if (tot == -1)
			{
				t--;
				continue;
			}
			key[b] = t;
			break;
		}
	}
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
		LL l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", solve(r) - solve(l - 1));
	}
	return 0;
}