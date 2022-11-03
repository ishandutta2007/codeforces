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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		a[0] = 2 * INF;
		int ans = -1;
		for (int i = 1; i < n; i++)
		{
			while (a[i] < a[i + 1])
			{
				int j = i;
				while (a[j] == a[i]) j--;
				j++;
				int len = i - j + 1;
				int minv = min(a[i + 1], a[j - 1]);
				LL tot = len * (minv - a[i]);
				if (tot < k)
				{
					k -= tot;
					for (int t = j; t <= i; t++)
						a[t] = minv;
					continue;
				}
				int r = k % len;
				if (r == 0) r = len;
				r--;
				ans = i - r;
				break;
			}
			if (ans != -1) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}