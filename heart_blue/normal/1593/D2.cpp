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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
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
		sort(a + 1, a + n + 1);
		int flag = 0;
		for (int i = 1; i + n / 2 - 1 <= n; i++)
		{
			if (a[i] == a[i + n / 2 - 1])
				flag = 1;
		}
		if (flag)
		{
			puts("-1");
			continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			map<int, int> mc1;
			mc1[0] = 1;
			for (int j = i + 1; j <= n; j++)
			{
				map<int, int> mc2 = mc1;
				for (auto& p : mc1)
				{
					int g = gcd(p.first, a[j] - a[i]);
					mc2[g] = max(mc2[g], p.second + 1);
				}
				mc1.swap(mc2);
			}
			for (auto& p : mc1)
			{
				if (p.second >= n / 2)
					ans = max(ans, p.first);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}