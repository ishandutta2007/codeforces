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
		vector<pair<int, int>> vp;
		while (n--)
		{
			int sz;
			scanf("%d", &sz);
			vector<int> v(sz);
			int maxv = 0;
			for (int i = 0; i < sz; i++)
			{
				int x;
				scanf("%d", &x);
				maxv = max(maxv, x - i);
			}
			vp.emplace_back(maxv, sz);
		}
		sort(vp.begin(), vp.end());
		int ans = 0;
		int cur = 0;
		for (auto& [x, d] : vp)
		{
			if (x >= cur)
			{
				ans += x - cur + 1;
				cur = x + 1;
			}
			cur += d;
		}
		printf("%d\n", ans);
	}
	return 0;
}