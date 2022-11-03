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
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int cnt0 = count(a + 1, a + n + 1, 0);
		int cnt1 = count(a + 1, a + n + 1, 1);
		if (cnt1 == 0)
		{
			puts("YES");
			continue;
		}
		if (cnt0 > 0)
		{
			puts("NO");
			continue;
		}
		int flag = 0;
		for (int i = 2; i <= n; i++)
		{
			if (a[i] - a[i - 1] == 1)
				flag = 1;
		}
		if (flag) puts("NO");
		else puts("YES");
	}
	return 0;
}