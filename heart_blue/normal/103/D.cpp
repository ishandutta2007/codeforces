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
typedef long long LLL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 600;
const int M = 550;
int a[N];
LL sum[N];
LL ans[N];
vector<pair<int, int>> vp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		vp[b].emplace_back(a, i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (i <= M)
		{
			for (int j = n; j >= 1; j--)
			{
				sum[j] = a[j] + sum[j + i];
			}
			for (auto [x, id] : vp[i])
				ans[id] = sum[x];
		}
		else
		{
			for (auto [x, id] : vp[i])
			{
				LL tot = 0;
				for (int j = x; j <= n; j += i)
					tot += a[j];
				ans[id] = tot;
			}
		}
	}
	for (int i = 1; i <= q; i++)
		printf("%lld\n", ans[i]);
	return 0;
}