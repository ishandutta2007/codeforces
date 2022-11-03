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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		vector<pair<LL, int>> vp;
		int n;
		scanf("%d", &n);
		LL s;
		scanf("%lld", &s);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &sum[i]);
			sum[i] += sum[i - 1];
		}
		sum[n + 1] = -INF * INF;
		vp.emplace_back(sum[n + 1], n + 1);
		int ans = 0;
		int L = -1;
		for (int i = n; i >= 1; i--)
		{
			pair<LL, int> cur = { sum[i],i };
			while (!vp.empty() && cur < vp.back()) vp.pop_back();
			vp.push_back(cur);
			int l = 0, r = vp.size() - 1;
			int key = 0;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (s - sum[i - 1] + vp[mid].first < 0) key = vp[mid].second - i, l = mid + 1;
				else r = mid - 1;
			}
			if (ans < key)
			{
				ans = key;
				L = i;
			}
		}
		if (ans == 0) puts("-1");
		else printf("%d %d\n", L, L + ans - 1);
	}
	return 0;
}