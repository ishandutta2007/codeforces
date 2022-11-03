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
const int N = 2e3 + 10;
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
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum ^= a[i];
		}
		if (sum == 0)
		{
			puts("YES");
			continue;
		}
		int cur = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cur ^= a[i];
			if (cur == sum)
			{
				cnt++;
				cur = 0;
			}
		}
		if (cnt > 1) puts("YES");
		else puts("NO");
	}
	return 0;
}