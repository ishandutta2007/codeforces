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
int a[N];
int dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ptr = 1;
	for (int i = 1; i <= n; i++)
	{
		while (a[ptr] + 5 < a[i]) ptr++;
		for (int j = 0; j <= k; j++) dp[i][j] = dp[i - 1][j];
		for (int j = 1; j <= k; j++) dp[i][j] = max(dp[i][j], dp[ptr - 1][j - 1] + (i - ptr + 1));
		for (int j = 1; j <= k; j++) dp[i][j] = max(dp[i][j - 1], dp[i][j]);
	}
	cout << dp[n][k] << endl;

	return 0;
}