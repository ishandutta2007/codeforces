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
const int N = 3e1 + 10;
map<int, int> mc;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; INF >> i; i++)
	{
		mc[1 << i] = i;
	}
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(a, 0);
		LL k;
		scanf("%lld", &k);
		int n;
		scanf("%d", &n);
		LL tot = 0;
		MEM(a, 0);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			a[mc[x]]++;
			tot += x;
		}
		if (tot < k)
		{
			puts("-1");
			continue;
		}
		int ans = 0;
		while (1)
		{
			LL tot = k;
			memcpy(b, a, sizeof(a));
			for (int i = 30; i >= 0; i--)
			{
				LL o = min(tot / (1 << i), a[i] * 1LL);
				tot -= o * (1 << i);
				b[i] -= o;
			}
			if (tot == 0) break;
			ans++;
			for (int i = 1; i <= 30; i++)
			{
				if (tot > (1 << i)) continue;
				if (b[i])
				{
					a[i]--;
					a[i - 1] += 2;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}