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
const int N = 5e2 + 10;
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
		int cur = 0;
		int maxv = 0;
		map<int, int> mc;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x] = 1;
			maxv = max(maxv, x);
		}
		while (k--)
		{
			while (mc.count(cur))
				cur++;
			int val = (cur + maxv + 1) / 2;
			if (mc.count(val))
			{
				k = 0;
				break;
			}
			mc[val] = 1;
			if (val > maxv)
			{
				break;
			}
		}
		printf("%d\n", mc.size() + max(0, k));
	}

	return 0;
}