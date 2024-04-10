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
	int n;
	scanf("%d", &n);
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		mc[x]++;
	}
	int l = mc.begin()->first;
	int r = mc.rbegin()->first;
	if (r - l + 1 != mc.size() || mc.size() == 1 || n % 2 == 1)
	{
		puts("NO");
		return 0;
	}
	mc[l]--;
	mc[r]--;
	for (int i = l + 1; i < r; i++)
	{
		if (mc[i] < 2)
		{
			puts("NO");
			return 0;
		}
		mc[i] -= 2;
	}
	int rest = 0;
	for (int i = l; i < r; i++)
	{
		int o = min(mc[i], mc[i + 1]);
		mc[i] -= o;
		mc[i + 1] -= o;
		rest += mc[i];
	}
	rest += mc[r];
	if (rest > 0) puts("NO");
	else puts("YES");
	return 0;
}