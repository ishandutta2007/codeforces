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
const int N = 1e3 + 10;
int dp1[N];
int dp2[N * N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	MEM(dp1, 0x3f);
	dp1[1] = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i + i / j >= N) continue;
			dp1[i + i / j] = min(dp1[i + i / j], dp1[i] + 1);
			j = i / (i / j);
		}
	}
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		vector<pair<int, int>> vp;
		int tot = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			vp.emplace_back(dp1[x], 0);
			tot += dp1[x];
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			sum += x;
			vp[i].second = x;
		}
		if (tot <= k)
		{
			printf("%d\n", sum);
			continue;
		}
		fill(dp2, dp2 + k + 1, 0);
		for (auto [w, c] : vp)
		{
			for (int i = k; i >= w; i--)
				dp2[i] = max(dp2[i], dp2[i - w] + c);
		}
		printf("%d\n", dp2[k]);

	}
	return 0;
}