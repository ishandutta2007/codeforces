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
		map<int, int> mc;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			while (x % 2 == 0) x /= 2;
			mc[x]++;
		}
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (flag == 0) continue;
			while (x)
			{
				if (mc.count(x))
				{
					if (mc[x]-- == 1)
						mc.erase(x);
					break;
				}
				x /= 2;
			}
			if (x == 0)
				flag = 0;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}