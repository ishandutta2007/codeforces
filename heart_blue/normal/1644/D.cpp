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
pair<int, int> a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, k, q;
		scanf("%d%d%d%d", &n, &m, &k, &q);
		map<int, int> flag1, flag2;
		for (int i = 1; i <= q; i++)
		{
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = q; i >= 1; i--)
		{
			auto [x, y] = a[i];
			int o1 = 0;
			int o2 = 0;
			if (!flag1.count(x) && cnt2 != m)
			{
				flag1[x] = i;
				o1 = 1;
			}
			if (!flag2.count(y) && cnt1 != n)
			{
				flag2[y] = i;
				o2 = 1;
			}
			cnt1 += o1;
			cnt2 += o2;
		}
		map<int, int> mc;
		for (auto& p : flag1)
			mc[p.second] = 1;
		for (auto& p : flag2)
			mc[p.second] = 1;
		mc.erase(0);
		LL ans = 1;
		for (int i = 1; i <= mc.size(); i++)
			ans = ans * k % 998244353;
		printf("%lld\n", ans);
	}
	return 0;
}