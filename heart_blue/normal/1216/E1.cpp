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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL multy(LL x, LL y)
{
	if (y == 0) return 0;
	if (x > INF* INF / y) return INF * INF;
	else return x * y;
}
LL sum(LL n)
{
	LL a = n;
	LL b = (n + 1);
	if (a & 1) b /= 2;
	else a /= 2;
	return multy(a, b);
}
void solve(LL n)
{
	LL l = 1, r = 9;
	int len = 1;
	while (1)
	{
		if ((r - l + 1) * len < n)
		{
			n -= (r - l + 1) * len;
			l *= 10;
			r = r * 10 + 9;
			len++;
			continue;
		}
		int key = (n - 1) / len;
		putchar(to_string(l + key)[(n - 1) % len]);
		puts("");
		break;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		LL n;
		scanf("%lld", &n);
		LL l = 1, r = 9;
		LL len = 1;
		LL pre = 0;
		while (1)
		{
			if (n > multy(pre, r - l + 1) + multy(sum(r - l + 1), len))
			{
				n -= multy(pre, r - l + 1) + multy(sum(r - l + 1), len);
				pre += multy(len, r - l + 1);
				len++;
				l *= 10;
				r = r * 10 + 9;
				continue;
			}
			LL L = l, R = r;
			LL key = l - 1;
			while (L <= R)
			{
				LL mid = (L + R) / 2;
				if (n > multy(pre, mid - l + 1) + multy(sum(mid - l + 1), len)) key = mid, L = mid + 1;
				else R = mid - 1;
			}
			n -= multy(pre, key - l + 1) + multy(sum(key - l + 1), len);
			solve(n);
			break;
		}
	}
	return 0;
}