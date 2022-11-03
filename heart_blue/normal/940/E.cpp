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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
LL dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	LL ans = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ans += a[i];
	deque<int> q;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		if (i >= k)
		{
			dp[i] = max(dp[i], dp[i - k] + a[q.front()]);
		}
		while (!q.empty() && q.front() + k - 1 <= i) q.pop_front();
	}
	printf("%lld\n", ans - dp[n]);
	return 0;
}