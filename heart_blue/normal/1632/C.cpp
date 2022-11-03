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
const int N = 3e6 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int n = 1;
		while (n <= b) n *= 2;
		fill(ans, ans + n, 0x3fffffff);
		int res = b - a;
		for (int i = n - 1; i >= 1; i--)
		{
			if (i >= b) ans[i] = i - b;
			int x = i;
			while (x)
			{
				int o = x & -x;
				ans[i - o] = min(ans[i - o], ans[i]);
				x -= o;
			}
		}
		for (int i = a; i < b; i++)
		{
			res = min(res, i - a + ans[i] + 1);
		}
		printf("%d\n", res);

	}
	return 0;
}