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
const int N = 4e4 + 10;
bool check(int x)
{
	string s1 = to_string(x);
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	return s1 == s2;
}
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	dp[0] = 1;
	for (int o = 1; o < N; o++)
	{
		if (!check(o)) continue;
		for (int i = o; i < N; i++)
		{
			dp[i] += dp[i - o];
			if (dp[i] >= INF) dp[i] -= INF;
		}
	}
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}