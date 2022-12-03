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
LL sum[N];
int xsum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		vector<int> vp;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x) vp.emplace_back(i);
			sum[i] = x + sum[i - 1];
			xsum[i] = x ^ xsum[i - 1];
		}
		vp.emplace_back(n + 1);
		while (q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l = lower_bound(vp.begin(), vp.end(), l) - vp.begin();
			if (vp[l] > r)
			{
				printf("%d %d\n", r, r);
				continue;
			}
			r = upper_bound(vp.begin(), vp.end(), r) - vp.begin() - 1;
			int l1 = l, r1 = min(r, l + 30);
			int l2 = max(r - 30, l), r2 = r;
			tuple<LL, int, int> ans = { 0LL,0,0 };
			for (int i = l1; i <= r1; i++)
			{
				for (int j = max(i, l2); j <= r2; j++)
				{
					int a = vp[i];
					int b = vp[j];
					ans = max(ans, { sum[b] - sum[a - 1] - (xsum[b] ^ xsum[a - 1]),a - b,b });
				}
			}
			auto [o, ans1, ans2] = ans;
			printf("%d %d\n", ans1 + ans2, ans2);
		}
	}
	return 0;
}