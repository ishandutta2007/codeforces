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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
pair<int, int> p[N];
int move(int r1, int c1, int r2, int c2)
{
	if (r1 == r2 && c1 == c2) return 0;
	if (r2 - r1 == c2 - c1)
		return (((r1 + c1) & 1) ^ 1) * (r2 - r1);
	if (c1 == c2)
	{
		int o = (r1 + c1) & 1;
		return (r2 - r1 + o) / 2;
	}
	if ((r1 + c1) & 1) r1++, c1++;
	else r1++;
	int ans = 0;
	r1 += c2 - c1;
	c1 = c2;
	if (r1 == r2) return 0;
	int o = (r1 + c1) & 1;
	return (r2 - r1 + o) / 2;
}
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
		for (int i = 1; i <= n; i++) scanf("%d", &p[i].first);
		for (int i = 1; i <= n; i++) scanf("%d", &p[i].second);
		sort(p + 1, p + n + 1);
		p[0] = { 1,1 };
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += move(p[i - 1].first, p[i - 1].second, p[i].first, p[i].second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}