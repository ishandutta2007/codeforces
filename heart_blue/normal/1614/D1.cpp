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
const int M = 2e7 + 10;
LL dp[M];
int cnt[M];
int tot[M];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int maxv = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	maxv = v.back();
	// dp[d] = max(dp[x] + (tot[x] - tot[d]) * d)
	for (int i = maxv; i >= 1; i--)
	{
		//if (maxv / i < v.size())
		{
			for (int j = 1; i * j <= maxv; j++)
			{
				tot[i] += cnt[i * j];
			}
			dp[i] = 1LL * tot[i] * i;
			for (int j = 1; i * j <= maxv; j++)
			{
				dp[i] = max(dp[i], dp[i * j] + 1LL * (tot[i] - tot[i * j]) * i);
			}
		}
		/*else
		{
			int sz = v.size();
			for (int j = sz - 1; j >= 0; j--)
			{
				if (v[j] < i) break;
				if (v[j] % i) continue;
				tot[i] += cnt[v[j]];
			}
			dp[i] = 1LL * tot[i] * i;
			for (int j = sz - 1; j >= 0; j--)
			{
				if (v[j] <= i) break;
				if (v[j] % i) continue;
				int x = v[j];
				dp[i] = max(dp[i], dp[x] + 1LL * (tot[i] - tot[x]) * i);
			}
		}*/
	}
	LL ans = 0;
	for (int i = 0; i < M; i++)
		ans = max(ans, dp[i]);
	printf("%lld\n", ans);
	return 0;
}