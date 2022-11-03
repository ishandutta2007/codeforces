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
const int N = 5e3 + 10;
LL dp[N];
int tag[N];
int s[N];
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
		for (int i = 1; i <= n; i++) scanf("%d", &tag[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
		MEM(dp, 0);
		for (int i = n; i >= 1; i--)
		{
			for (int j = 1; j < i; j++)
			{
				if (tag[i] == tag[j]) continue;
				int o = abs(s[i] - s[j]);
				tie(dp[i], dp[j]) = make_pair(max(dp[i], dp[j] + o), max(dp[j], dp[i] + o));
			}
		}
		LL ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, dp[i]);
		printf("%lld\n", ans);
	}
	return 0;

}