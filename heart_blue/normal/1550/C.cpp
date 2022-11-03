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
		{
			scanf("%d", &a[i]);
		}
		int ptr = 1;
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			while (ptr <= n)
			{
				int flag = 1;
				for (int j = i; j < ptr; j++)
				{
					for (int k = j + 1; k < ptr; k++)
					{
						if ((a[j] <= a[k] && a[k] <= a[ptr]) ||
							(a[j] >= a[k] && a[k] >= a[ptr]))
						{
							flag = 0;
							break;
						}
					}
					if (flag == 0)
						break;
				}
				if (flag == 0) break;
				ptr++;
			}
			ans += ptr - i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}