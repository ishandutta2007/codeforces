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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int last[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	while (m--)
	{
		int x;
		scanf("%d", &x);
		flag[x] = 1;
	}
	if (flag[0])
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (flag[i]) last[i] = last[i - 1];
		else last[i] = i;
	}
	LL ans = INF * INF;
	for (int i = 1; i <= k; i++)
	{
		int x;
		scanf("%d", &x);
		int cur = 0;
		LL tot = 0;
		while (1)
		{
			tot += x;
			if (cur + i >= n)
				break;
			if (last[cur + i] == cur)
			{
				tot = ans;
				break;
			}
			cur = last[cur + i];
		}
		ans = min(ans, tot);
	}
	if (ans == INF * INF) ans = -1;
	printf("%lld\n", ans);
	return 0;
}