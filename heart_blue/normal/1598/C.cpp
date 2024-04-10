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
const int N = 3e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		map<LL, int> mc;
		scanf("%d", &n);
		LL tot = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x]++;
			tot += x;
		}
		if (tot * 2 % n)
		{
			puts("0");
			continue;
		}
		LL key = tot * 2 / n;
		LL ans = 0;
		for (auto& p : mc)
		{
			LL x = p.first;
			if (x * 2 == key) ans += p.second * (p.second - 1LL);
			else if (mc.count(key - x)) ans += 1LL * p.second * mc[key - x];
		}
		printf("%lld\n", ans / 2);
	}
	return 0;
}