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
		if (a[n] == 0)
		{
			for (int i = 1; i <= n + 1; i++)
			{
				printf("%d%c", i, " \n"[i == n + 1]);
			}
			continue;
		}
		if (a[1] == 1)
		{
			printf("%d", n + 1);
			for (int i = 1; i <= n; i++)
			{
				printf(" %d", i);
			}
			puts("");
			continue;
		}
		int flag = 0;
		for (int i = 1; i + 1 <= n; i++)
		{
			if (a[i] == 0 && a[i + 1] == 1)
			{
				flag = 1;
				for (int j = 1; j <= i; j++)
					printf("%d ", j);
				printf("%d", n + 1);
				for (int j = i + 1; j <= n; j++)
					printf(" %d", j);
				puts("");
				break;
			}
		}
		if (flag == 0) puts("-1");
	}
	return 0;
}