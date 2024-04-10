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
const int N = 5e2 + 10;
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
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			cnt += x;
		}
		cnt = min(cnt, n - cnt);
		if (cnt != 0)
		{
			puts("Yes");
			continue;
		}
		int ok = 1;
		for (int i = 1; i <= n; i++)
		{
			if (a[i - 1] > a[i])
				ok = 0;
		}
		if (ok) puts("Yes");
		else puts("No");
	}
	return 0;
}