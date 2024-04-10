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
const int N = 1e2 + 10;

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
		vector<pair<int, int>> vp(3);
		for (auto& [x, y] : vp)
			scanf("%d%d", &x, &y);
		int a = vp[0].first == vp[1].first ? vp[0].first : vp[2].first;
		int b = vp[0].second == vp[1].second ? vp[0].second : vp[2].second;

		int kx, ky;
		scanf("%d%d", &kx, &ky);
		int flag = 0;
		for (auto& [x, y] : vp)
		{
			if (x % 2 == kx % 2 && y % 2 == ky % 2)
				flag = 1;
		}
		if ((a == 1 || a == n) && (b == 1 || b == n))
		{
			if (a == kx || b == ky) puts("YES");
			else puts("NO");
		}
		else if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}