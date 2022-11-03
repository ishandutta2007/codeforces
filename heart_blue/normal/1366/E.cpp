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
const int N = 3e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	LL ans = 1;
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		mc[a[i]] = i;
	}
	a[n + 1] = INF;
	mc[INF] = n + 1;
	n++;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
	}
	b[m + 1] = INF;
	m++;
	if (b[1] > mc.begin()->first)
	{
		puts("0");
		return 0;
	}
	const int mod = 998244353;
	for (int i = 1; i < m; i++)
	{
		if (!mc.count(b[i]) || !mc.count(b[i + 1]))
		{
			puts("0");
			return 0;
		}

		int l = mc[b[i]];
		int r = mc[b[i + 1]];
		if (l > r)
		{
			puts("0");
			return 0;
		}
		int key = l;
		int x = b[i];
		while (l < r)
		{
			if (a[l] < b[i + 1])
				key = l;
			if (a[l] < x)
			{
				puts("0");
				return 0;
			}
			l++;
		}
		ans = ans * (r - key) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}