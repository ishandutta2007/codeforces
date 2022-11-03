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
const LL INF = 1e9 + 9;
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
		int n, k;
		scanf("%d%d", &n, &k);
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum = (sum + a[i]) % k;
		}
		if (sum != 0)
		{
			printf("%d\n", n);
			continue;
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] % k == 0) cnt1++;
			else break;
		}
		for (int i = n; i >= 1; i--)
		{
			if (a[i] % k == 0) cnt2++;
			else break;
		}
		cnt1++, cnt2++;
		if (cnt1 >= n) puts("-1");
		else printf("%d\n", n - min(cnt1, cnt2));
	}
	return 0;
}