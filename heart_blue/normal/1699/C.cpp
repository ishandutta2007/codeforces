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
LL fact[N];
int pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = fact[i - 1] * i % INF;
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			pos[x] = i;
		}
		int l = pos[0], r = pos[0];
		LL ans = 1;
		int rest = 0;
		for (int i = 1; i < n; i++)
		{
			int p = pos[i];
			if (p >= l && p <= r)
			{
				ans = ans * rest-- % INF;
				continue;
			}
			int len1 = r - l + 1;
			l = min(l, p);
			r = max(r, p);
			int len2 = r - l + 1;
			rest += len2 - len1 - 1;
		}
		printf("%lld\n", ans);

	}
	return 0;
}