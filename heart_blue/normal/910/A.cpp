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
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d;
	string str;
	cin >> n >> d;
	cin >> str;
	MEM(dp, 0x3f);
	int inf = 0x3f3f3f3f;
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '0') continue;
		for (int j = 1; j <= d && i + j < n; j++)
		{
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[n - 1] == inf) dp[n - 1] = -1;
	cout << dp[n - 1] << endl;
	return 0;
}