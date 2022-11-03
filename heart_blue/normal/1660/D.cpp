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
const int N = 4e5 + 10;
int a[N];
tuple<int, int, int> solve(int l, int r)
{
	if (l > r) return { 0,2,1 };
	int cnt = 0;
	for (int i = l; i <= r; i++)
	{
		if (abs(a[i]) == 2)
			cnt++;
	}
	return { cnt,l,r };
}
tuple<int, int, int> check(int l, int r)
{
	int o = 0;
	int kl = INF, kr = 0;
	for (int i = l; i <= r; i++)
	{
		if (a[i] < 0)
			o ^= 1, kl = min(kl, i), kr = i;
	}
	if (o == 0) return solve(l, r);
	else return max(solve(kl + 1, r), solve(l, kr - 1));
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
			scanf("%d", &a[i]);
		int pre = 1;
		a[n + 1] = 0;
		tuple<int, int, int> ans = { 0,2,1 };
		for (int i = 1; i <= n + 1; i++)
		{
			if (a[i] == 0)
			{
				ans = max(ans, check(pre, i - 1));
				pre = i + 1;
			}
		}
		int l, r;
		tie(ignore, l, r) = ans;
		printf("%d %d\n", l - 1, n - r);
	}

	return 0;
}