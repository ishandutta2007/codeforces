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
const int N = 3e5 + 10;
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
		int l = 0, r = n + 1;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int sum1 = 0, sum2 = 0;
		int ans = 0;
		while (l < r)
		{
			if (sum1 == sum2)
			{
				ans = l + n - r + 1;
			}
			if (sum1 < sum2) sum1 += a[++l];
			else sum2 += a[--r];
		}
		printf("%d\n", ans);
	}
	return 0;

}