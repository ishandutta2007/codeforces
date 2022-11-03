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
LL a[N];
LL sum[N];
bool check(int last, int key)
{
	return a[last] == sum[last - 1] - a[key];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n + 2; i++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + n + 3);
		for (int i = 1; i <= n + 2; i++)
			sum[i] = a[i] + sum[i - 1];
		int last = -1, key = -1;
		for (int i = 1; i <= n + 1; i++)
		{
			if (check(n + 2, i))
			{
				last = n + 2, key = i;
			}
		}
		if (check(n + 1, 0))
			last = n + 1, key = 0;
		if (last == -1) puts("-1");
		else
		{
			for (int i = 1; i < last; i++)
			{
				if (i == key) continue;
				printf("%lld ", a[i]);
			}
			puts("");
		}
	}
	return 0;
}