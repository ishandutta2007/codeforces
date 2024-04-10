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
const int N = 5e3 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	char pre = 's';
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		if (pre == 'f')
		{
			for (int i = n; i > 0; i--) dp[i] = dp[i - 1];
			dp[0] = 0;
		}
		else
		{
			for (int i = n - 1; i >= 0; i--)
			{
				dp[i] += dp[i + 1];
				if (dp[i] >= INF) dp[i] -= INF;
			}
		}
		pre = c;
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) ans = (ans + dp[i]) % INF;
	cout << ans << endl;
	return 0;
}