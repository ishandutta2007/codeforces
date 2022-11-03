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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	dp[0] = 1;
	for (int o = 11; o < N; o = o * 10 + 1)
	{
		for (int i = o; i < N; i++)
			dp[i] |= dp[i - o];
	}
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		if (n >= N || dp[n]) puts("YES");
		else puts("NO");
	}
	return 0;
}