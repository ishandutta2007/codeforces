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
const int N = 1e3 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, c0, d0;
	cin >> n >> m >> c0 >> d0;
	MEM(dp, 0);
	for (int i = 0; i * c0 <= n; i++) dp[i*c0] = i*d0;
	while (m--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = n; i >= c; i--)
		{
			int cnt = min(i / c, a / b);
			for (int j = 1; j <= cnt; j++)
			{
				dp[i] = max(dp[i], dp[i - j*c] + d*j);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}