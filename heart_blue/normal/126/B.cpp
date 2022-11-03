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
const int N = 1e6 + 10;
char str[N];
int fail[N];
int sz[N];
void getfail(char *str, int n)
{
	int k = -1;
	fail[0] = -1;
	for (int i = 1; i < n; i++)
	{
		while (k >= 0 && str[k + 1] != str[i]) k = fail[k];
		if (str[i] == str[k + 1]) k++;
		fail[i] = k;
		if (k >= 0) sz[k]++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str);
	int n = strlen(str);
	getfail(str, n);
	if (fail[n - 1] == -1)
	{
		puts("Just a legend");
		return 0;
	}
	if (sz[fail[n - 1]] >= 2)
	{
		str[fail[n - 1] + 1] = 0;
		puts(str);
		return 0;
	}
	int cur = fail[n - 1];
	while (cur != -1)
	{
		int len = fail[cur];
		if (sz[len] >= 1)
		{
			str[len + 1] = 0;
			puts(str);
			return 0;
		}
		cur = fail[cur];
	}
	puts("Just a legend");
	return 0;
}