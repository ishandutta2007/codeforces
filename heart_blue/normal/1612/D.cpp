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
int a[N];
int b[N];
pair<int, int> combine(int l1, int r1, int l2, int r2, int len)
{
	l1 = max(l1, 1);
	l2 = max(l2, 1);
	r1 = min(r1, len);
	r2 = min(r2, len);
	return { max(l1,l2),min(r1,r2) };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL a, b, x;
		scanf("%lld%lld%lld", &a, &b, &x);
		int ok = 0;
		if (a == x || b == x) ok = 1;
		while (a != b)
		{
			if (a < b) swap(a, b);
			b = min(b, a - b);
			if (a >= x && x >= b)
			{
				if (b == 0)
				{
					if (x == a)
					{
						ok = 1;
					}
					break;
				}
				if ((a - x) % b == 0)
				{
					ok = 1;
					break;
				}
			}
			if (b == 0) break;
			tie(a, b) = make_pair(b, a % b);
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}