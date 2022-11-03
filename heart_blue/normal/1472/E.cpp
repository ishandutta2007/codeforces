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
int ans[N];
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
		vector < tuple<int, int, int> > vp;
		fill(ans + 1, ans + n + 1, -1);
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			vp.emplace_back(x, -y, i);
			vp.emplace_back(y, -x, i);
		}
		sort(vp.begin(), vp.end());
		pair<int, int> minv = { int(INF),-1 };
		for (auto [x, y, id] : vp)
		{
			y = -y;
			if (y > minv.first)
			{
				ans[id] = minv.second;
			}
			minv = min(minv, { y,id });
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}