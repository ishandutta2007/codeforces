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
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, l, r;
		scanf("%d%d%d", &n, &l, &r);
		map<int, int> mc;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (i <= l) mc[x]++;
			else mc[x]--;
		}
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt11 = 0;
		int cnt22 = 0;
		for (auto [key, val] : mc)
		{
			if (val > 0)
			{
				cnt1 += val;
				cnt11 += val & 1;
			}
			if (val < 0)
			{
				val = -val;
				cnt2 += val;
				cnt22 += val & 1;
			}
		}
		if (cnt1 < cnt2) swap(cnt1, cnt2), swap(cnt11, cnt22);
		int ans = cnt2 + (cnt1 - cnt2) / 2 + max(0, cnt11 - cnt2) / 2;
		printf("%d\n", ans);
	}
	return 0;
}