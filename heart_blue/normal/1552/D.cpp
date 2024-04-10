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
const int N = 2e3 + 10;
int sum[N];
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
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			sum[1 << i] = abs(x);
			if (x == 0)
				flag = 1;
		}
		int tot = 1 << n;
		for (int i = 1; i < tot; i++)
		{
			sum[i] = sum[i - (i & -i)] + sum[i & -i];
		}
		for (int i = 1; i < tot; i++)
		{
			for (int j = 1; j < tot; j++)
			{
				if (i & j) continue;
				if (sum[i] == sum[j])
					flag = 1;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}