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
LL dis(int a, int b, int c, int d)
{
	return abs(c - a) + abs(d - b);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL n;
		scanf("%lld", &n);
		n = (n + 1) / 2;
		LL ans = INF * INF;
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 3; j++)
			{
				for (int k = 0; k <= 3; k++)
				{
					LL rest = n - i * 3 - j * 4 - k * 5;
					rest = max(rest, 0LL);
					LL o = min({ (rest + 2) / 3 * 3,
						(rest + 3) / 4 * 4,
						(rest + 4) / 5 * 5 });
					ans = min(ans, o + i * 3 + j * 4 + k * 5);
				}
			}
		}
		printf("%lld\n", ans * 5);
	}
	return 0;
}