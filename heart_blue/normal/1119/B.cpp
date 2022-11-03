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
const int N = 2e5 + 10;
LL dp[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, h;
	cin >> n >> h;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = min(n, 2);
	for (int i = 3; i <= n; i++)
	{
		sort(a + 1, a + i + 1);
		dp[1] = a[1], dp[2] = a[2];
		for (int j = 2; j <= i; j++)
			dp[j] = min(dp[j - 2], dp[j - 1]) + a[j];
		if (dp[i] <= h)
			ans = i;
	}
	cout << ans << endl;
	return 0;
}