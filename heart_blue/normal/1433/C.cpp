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
		int maxv = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] > maxv)
				maxv = a[i];
		}
		int cnt = count(a + 1, a + n + 1, maxv);
		if (cnt == n)
		{
			puts("-1");
			continue;
		}
		a[0] = INF, a[n + 1] = INF;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != maxv) continue;
			if (a[i] > a[i - 1] || a[i] > a[i + 1])
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}