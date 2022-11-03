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
const int N = 1e6 + 10;
int flag[N];
int a[N];
void init()
{
	fill(flag + 1, flag + N, 1);
	for (int i = 2; i < N; i++)
	{
		if (flag[i] != 1) continue;
		flag[i] = 2;
		for (int j = i + i; j < N; j += i)
		{
			flag[j] = 0;
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
		int n, e;
		scanf("%d%d", &n, &e);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			a[i] = flag[x];
		}
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != 2) continue;
			int l = 1, r = 1;
			for (int j = 1; i - e * j >= 1; j++)
			{
				if (a[i - e * j] != 1) break;
				l++;
			}
			for (int j = 1; i + e * j <= n; j++)
			{
				if (a[i + e * j] != 1) break;
				r++;
			}
			ans += 1LL * l * r - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}