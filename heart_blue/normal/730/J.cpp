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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int dp[N][N*N];
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0xFF);
	int n;
	cin >> n;
	int sum = 0;
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	for (int i = 1; i <= n; i++) cin >> b[i], pq.push(b[i]);
	int tmp = sum;
	int k = 0;
	while (!pq.empty())
	{
		k++;
		tmp -= pq.top();
		pq.pop();
		if (tmp <= 0) break;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			for (int o = sum + b[i]; o >= b[i]; o--)
			{
				if (dp[j - 1][o - b[i]] == -1) continue;
				dp[j][o] = max(dp[j][o], dp[j - 1][o - b[i]] + a[i]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 100; i++)
	{
		ans = max(ans, dp[k][sum + i]);
	}
	printf("%d %d\n", k, sum - ans);

	return 0;
}