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
const int N = 1e2 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	dp[m] = 1;
	dp[k] = 3;
	int o = 1;
	string str;
	char op[10];
	scanf("%*s%s", op);
	if (op[0] == 'h') o = -1;
	cin >> str;
	int ans = 0;
	for (auto& c : str)
	{
		ans++;
		if (k == 1) o = 1;
		if (k == n) o = -1;
		if (c == '0')
		{
			for (int i = 1; i <= n; i++)
			{
				if (dp[i + 1] == 1)
					dp[i] |= 1;
			}
			for (int i = n; i >= 1; i--)
			{
				if (dp[i - 1] == 1)
					dp[i] |= 1;
			}
			dp[k + o] = 3;
			dp[k] = 0;
			k += o;
			if (count(dp + 1, dp + n + 1, 1) == 0) printf("Controller %d\n", ans), exit(0);
		}
		else
		{
			MEM(dp, 0);
			dp[k + o] = 3;
			k += o;
			for (int i = 1; i <= n; i++) dp[i] |= 1;
		}
	}
	puts("Stowaway");
	return 0;
}