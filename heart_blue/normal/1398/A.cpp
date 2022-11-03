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
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			vp.emplace_back(x, i);
		}
		sort(vp.begin(), vp.end());
		if (vp[0].first + vp[1].first <= vp.back().first)
		{
			printf("%d %d %d\n", vp[0].second, vp[1].second, vp.back().second);
		}
		else
			puts("-1");
	}
	return 0;
}