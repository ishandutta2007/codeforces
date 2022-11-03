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
LL dp[N][10];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	scanf("%s", str + 1);
	int len = strlen(str + 1);
	for (int i = 2; i <= len; i++)
	{
		for (int d = 0; d < 10; d++)
		{
			int x = d + (str[i] - '0');
			dp[i][x / 2] += dp[i - 1][d];
			if (x & 1)
				dp[i][x / 2 + 1] += dp[i - 1][d];
		}
	}
	LL ans = 0;
	for (int i = 0; i < 10; i++)
		ans += dp[len][i];
	int flag = 1;
	for (int i = 2; i <= len; i++)
	{
		int x = (str[i - 1] - '0') + (str[i] - '0');
		if (x / 2 == str[i] - '0' || (x + 1) / 2 == str[i] - '0') continue;
		else
		{
			flag = 0;
			break;
		}
	}
	ans -= flag;
	cout << ans << endl;
	return 0;
}