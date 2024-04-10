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
const int N = 2e5 + 10;
map<int, int> mc;
int a[N];
void add(int x)
{
	mc[x]++;
}
void del(int x)
{
	mc[x]--;
	if (mc[x] == 0)
		mc.erase(x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k, d;
		scanf("%d%d%d", &n, &k, &d);
		mc.clear();
		int ans = INF;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			add(a[i]);
			if (i >= d) ans = min(ans, (int)mc.size());
			if (i - d + 1 >= 1)
				del(a[i - d + 1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}