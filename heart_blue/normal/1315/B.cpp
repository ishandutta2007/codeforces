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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char str[N];
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b, p;
		scanf("%d%d%d", &a, &b, &p);
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		dp[n] = dp[n + 1] = 0;
		int cnt = 1;
		int ans = n;
		for (int i = n - 1; i >= 1; i--)
		{
			if (str[i] == str[i + 1]) cnt++;
			else cnt = 1;
			if (str[i] == 'A') dp[i] = dp[i + cnt] + a;
			else dp[i] = dp[i + cnt] + b;
			if (dp[i] > p) break;
			ans = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}