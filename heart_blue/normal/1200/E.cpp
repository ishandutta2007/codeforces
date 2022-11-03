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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
char s1[N];
char s2[N];
char str[N * 2];
int fail[N * 2];
int kmp(int n)
{
	int j = 0;
	fail[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		while (j && str[j + 1] != str[i]) j = fail[j];
		if (str[j + 1] == str[i]) j++;
		fail[i] = j;
	}
	int ans = n;
	while (ans > n / 2)
		ans = fail[ans];
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", s1 + 1);
	int len1 = strlen(s1 + 1);
	while (--n)
	{
		scanf("%s", s2 + 1);
		int len2 = strlen(s2 + 1);
		int minv = min(len1, len2);
		int sz = 0;
		for (int i = 1; i <= minv; i++)
			str[++sz] = s2[i];
		for (int i = len1 - minv + 1; i <= len1; i++)
			str[++sz] = s1[i];
		int o = kmp(sz);
		for (int i = o + 1; i <= len2; i++)
			s1[++len1] = s2[i];
	}
	puts(s1 + 1);
	return 0;
}