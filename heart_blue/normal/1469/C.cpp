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
		int flag = 1;
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		LL l = a[1], r = a[1];
		for (int i = 2; i <= n; i++)
		{
			l -= k - 1;
			r += k - 1;
			l = max(l, 1LL * a[i]);
			r = min(r, a[i] + k - 1LL);
			if (l > r)
			{
				flag = 0;
			}
		}
		if (l != a[n])
			flag = 0;
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}