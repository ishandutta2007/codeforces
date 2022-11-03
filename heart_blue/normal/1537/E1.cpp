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
const int N = 1e6 + 10;
char str[N];
int fail[N];
int solve(int n)
{
	int j = 0;
	fail[1] = 0;
	int ret = n;
	for (int i = 2; i <= n; i++)
	{
		if (str[j + 1] < str[i])
		{
			ret = i - j - 1;
			break;
		}
		while (j && str[j + 1] != str[i]) j = fail[j];
		if (str[j + 1] == str[i]) j++;
		fail[i] = j;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	str[0] = ' ';
	scanf("%s", str + 1);
	for (int i = n + 1; i <= n * 2; i++)
		str[i] = str[i - n];
	n *= 2;
	str[n + 1] = 0;
	int len = solve(n);
	for (int i = len + 1; i <= k; i++)
		str[i] = str[i - len];
	str[k + 1] = 0;
	puts(str + 1);
	return 0;
}