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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
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
		vector<int> v[2];
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x == 0) continue;
			v[x < 0].push_back(abs(x));
		}
		LL ans = 0;
		int maxv[2] = { 0,0 };
		for (int o = 0; o < 2; o++)
		{
			sort(v[o].begin(), v[o].end());
			if (!v[o].empty())
				maxv[o] = v[o].back();
			while (v[o].size() > k)
			{
				int t = k;
				ans += v[o].back() * 2;
				while (t--)
				{
					v[o].pop_back();
				}
			}
			if (!v[o].empty())
				ans += v[o].back() * 2;
		}
		ans -= max(maxv[0], maxv[1]);
		printf("%lld\n", ans);
	}
	return 0;
}