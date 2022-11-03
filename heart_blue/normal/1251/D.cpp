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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		LL s;
		scanf("%d%lld", &n, &s);
		vector<pair<int, int>> vp;
		for (int i = 1; i <= n; i++)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			vp.emplace_back(l, r);
		}
		LL l = 0, r = INF * INF;
		LL ans = 0;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			int sum1 = 0, sum2 = 0;
			vector<LL> v;
			LL tot = 0;
			for (auto& p : vp)
			{
				if (mid < p.first)
				{
					sum2++;
					tot += p.first;
				}
				else if (mid > p.second)
				{
					sum1++;
					tot += p.first;
				}
				else
				{
					v.push_back(p.first);
				}
			}
			if (sum1 * 2 > n)
			{
				r = mid - 1;
				continue;
			}
			if (sum2 * 2 > n)
			{
				l = mid + 1;
				continue;
			}
			sort(v.rbegin(), v.rend());
			while (sum1 < n / 2)
			{
				sum1++;
				tot += v.back();
				v.pop_back();
			}
			tot += v.size() * mid;
			if (tot > s) r = mid - 1;
			else ans = mid, l = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}