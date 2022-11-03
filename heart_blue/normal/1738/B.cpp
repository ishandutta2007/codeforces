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
const int N = 1e5 + 10;
LL a[N];
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
		int flag = 1;
		for (int i = n - k + 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		if (k == 1)
		{
			puts("Yes");
			continue;
		}
		for (int i = n - k + 2; i < n; i++)
		{
			if (a[i] - a[i - 1] > a[i + 1] - a[i])
			{
				flag = 0;
			}
		}
		LL o = a[n - k + 2] - a[n - k + 1];
		if (flag && o * (n - k + 1) >= a[n - k + 1]) puts("YES");
		else puts("NO");

	}
	return 0;
}