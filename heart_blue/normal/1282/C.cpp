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
const int N = 3e5 + 10;
int check(int a, int b, int cnta, int cntb, int rest)
{
	if (a > b) swap(a, b), swap(cnta, cntb);
	int o = min(cnta, rest / a);
	rest -= o * a;
	return o + min(cntb, rest / b);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, t, a, b;
		scanf("%d%d%d%d", &n, &t, &a, &b);
		int cnta, cntb;
		cnta = cntb = 0;
		vector<pair<int, int>> vp;
		vp.emplace_back(0, 0);
		for(int i = 1; i <= n; i++)
		{
			int o;
			scanf("%d", &o);
			if (o == 0) o = a, cnta++;
			else o = b, cntb++;
			vp.emplace_back(0, o);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &vp[i].first);
		}
		vp.emplace_back(t + 1, 0);
		sort(vp.begin(), vp.end());
		LL cur = 0;
		int ans = 0;
		for (int i = 0; i + 1 < vp.size(); i++)
		{
			if (cnta > 0 && vp[i].second == a) cur += a, cnta--;
			else if (cntb > 0 && vp[i].second == b) cur += b, cntb--;
			if (vp[i].first != vp[i + 1].first)
			{
				LL rest = vp[i + 1].first - 1 - cur;
				if (rest < 0) continue;
				ans = max(ans, i + check(a, b, cnta, cntb, rest));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}