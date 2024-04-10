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
		int n, w;
		scanf("%d%d", &n, &w);
		map<int, int> mc;
		int rest = n;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			mc[x]++;
		}
		int ans = 0;
		while (rest > 0)
		{
			ans++;
			int cur = w;
			for (auto iter = mc.rbegin(); iter != mc.rend(); iter++)
			{
				if (cur >= iter->first && iter->second > 0)
				{
					int o = min(iter->second, cur / iter->first);
					rest -= o;
					iter->second -= o;
					cur -= iter->first * o;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}