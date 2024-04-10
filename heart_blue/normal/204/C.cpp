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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
__int128 sum1[N];
__int128 sum2[N];
char s1[N];
char s2[N];
__int128 solve(char c, int n, char s1[N], char s2[N])
{
	for (int i = 1; i <= n; i++)
	{
		sum1[i] = sum1[i - 1];
		if (s1[i] == c)
			sum1[i] += i;
	}
	__int128 ret = 0;
	for (int i = n; i >= 1; i--)
	{
		if (s2[i] == c)
			ret += sum1[i - 1] * (n - i + 1);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	__int128 tot1 = 0;
	__int128 tot2 = 0;
	for (char c = 'A'; c <= 'Z'; c++)
	{
		tot1 += solve(c, n, s1, s2) + solve(c, n, s2, s1);
	}
	for (int i = 1; i <= n; i++)
	{
		tot2 += 1LL * i * i;
		if (s1[i] == s2[i])
			tot1 += 1LL * i * (n - i + 1);
	}
	printf("%.15f\n", 1.0 * tot1 / tot2);
	return 0;
}