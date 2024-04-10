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
vector<int> vp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, d;
		LL c;
		scanf("%d%lld%d", &n, &c, &d);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		sort(v.begin(), v.end());
		if (v.back() * 1LL * d < c)
		{
			puts("Impossible");
			continue;
		}
		int l = 0, r = d + 2;
		int ans = -1;
		while (l <= r)
		{
			for (int i = 1; i <= d; i++) vp[i].clear();
			for (auto& x : v)
				vp[1].emplace_back(x);
			priority_queue<int> pq;
			LL sum = 0;
			int mid = (l + r) / 2;
			for (int i = 1; i <= d; i++)
			{
				for (auto& x : vp[i])
					pq.emplace(x);
				if (!pq.empty())
				{
					int x = pq.top();
					pq.pop();
					sum += x;
					if (i + mid + 1 <= d)
						vp[i + mid + 1].push_back(x);
				}
			}
			if (sum >= c) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (ans == d + 2) puts("Infinity");
		else printf("%d\n", ans);
	}
	return 0;
}