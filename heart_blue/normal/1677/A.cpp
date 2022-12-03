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
const int N = 5e3 + 10;

int a[N];
int b[N];
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
		LL ans = 0;
		for (int i = n; i >= 1; i--)
		{
			LL tot = 0;
			fill(b, b + n + 1, 0);
			for (int j = i + 1; j <= n; j++)
			{
				b[a[j]] = 1;
			}
			for (int i = 1; i <= n; i++)
				b[i] += b[i - 1];
			for (int j = i - 1; j >= 1; j--)
			{
				if (a[i] > a[j])
				{
					ans += tot;
				}
				tot += b[a[j]];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}