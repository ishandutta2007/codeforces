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
const int N = 3e2 + 10;
int dp[N];
LL multy(LL x, LL y)
{
	if (x > INF* INF / y) return INF * INF;
	else return x * y;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL x0, y0, ax, ay, bx, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	LL x, y, t;
	cin >> x >> y >> t;
	vector<pair<LL, LL>> vp;
	while (1)
	{
		if (x0 >= x || y0 >= y)
		{
			if (abs(x0 - x) + abs(y0 - y) > t) break;
		}
		if (abs(x0 - x) + abs(y0 - y) <= t)
			vp.emplace_back(x0, y0);
		tie(x0, y0) = make_pair(ax * x0 + bx, ay * y0 + by);
	}
	int ans = 0;
	for (int i = 0; i < vp.size(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int k = i; k < vp.size(); k++)
			{
				LL d = abs(vp[i].first - x) + abs(vp[i].second - y);
				LL len = abs(vp[k].first - vp[j].first) + abs(vp[k].second - vp[j].second);
				LL d1 = abs(vp[j].first - vp[i].first) + abs(vp[j].second - vp[i].second);
				LL d2 = abs(vp[k].first - vp[i].first) + abs(vp[k].second - vp[i].second);
				if (len + d + min(d1, d2) <= t)
				{
					ans = max(ans, k - j + 1);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}