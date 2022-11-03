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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<tuple<int, int, int>> vp;
		for (int i = 1; i <= n; i++)
		{
			int t, l, r;
			scanf("%d%d%d", &t, &l, &r);
			vp.emplace_back(t, l, r);
		}
		sort(vp.begin(), vp.end());
		int pre = 0;
		int l, r;
		l = r = m;
		int flag = 1;
		for (auto& p : vp)
		{
			int t, x, y;
			tie(t, x, y) = p;
			l -= t - pre;
			r += t - pre;
			l = max(l, x);
			r = min(r, y);
			pre = t;
			if (l > r)
			{
				flag = 0;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}