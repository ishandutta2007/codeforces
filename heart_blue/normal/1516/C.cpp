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
const int N = 2e3 + 10;
int a[N];
int dp[N * 100];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int g = 0;
	int sum = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		g = gcd(a[i], g);
		sum += a[i];
		for (int j = sum; j >= a[i]; j--)
		{
			dp[j] |= dp[j - a[i]];
		}
	}
	if (sum & 1)
	{
		puts("0");
		return 0;
	}
	if (dp[sum / 2] == 0)
	{
		puts("0");
		return 0;
	}
	sum /= g;
	for (int i = 1; i <= n; i++)
	{
		a[i] /= g;
		if (a[i] & 1)
		{
			puts("1");
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}