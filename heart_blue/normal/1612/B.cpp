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
const int N = 2e2 + 10;
int v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		MEM(v, 0);
		int r = n;
		for (int i = 1; i < a; i++)
		{
			v[r--] = i;
		}
		int l = 1;
		for (int i = 1; i <= n - b; i++)
		{
			v[l++] = n - i + 1;
		}
		for (int i = l; i <= r; i++)
		{
			v[i] = i - l + a;
		}
		map<int, int> mc;
		for (int i = 1; i <= n; i++)
		{
			mc[v[i]] = 1;
		}
		int minv = *min_element(v + 1, v + n / 2 + 1);
		int maxv = *max_element(v + n / 2 + 1, v + n + 1);
		if (mc.size() != n ||
			mc.begin()->first < 1 ||
			mc.rbegin()->first > n ||
			minv != a ||
			maxv != b)
		{
			puts("-1");
			continue;
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", v[i], " \n"[i == n]);
	}
	return 0;
}