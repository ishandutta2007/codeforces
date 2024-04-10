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
const int N = 5e5 + 10;
char s1[N], s2[N];
int fail[N];
void getfail(char* str, int n)
{
	int j = 0;
	for (int i = 2; i <= n; i++)
	{
		while (j && str[j + 1] != str[i]) j = fail[j];
		if (str[j + 1] == str[i]) j++;
		fail[i] = j;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s%s", s1 + 1, s2 + 1);
	int n = strlen(s1 + 1);
	int m = strlen(s2 + 1);
	int cnt[2];
	cnt[0] = count(s1 + 1, s1 + n + 1, '0');
	cnt[1] = n - cnt[0];
	getfail(s2, m);
	string ans;
	int j = 0;
	while (1)
	{
		while (j && cnt[s2[j + 1] - '0'] == 0) j = fail[j];
		if (cnt[s2[j + 1] - '0'])
		{
			j++;
			cnt[s2[j] - '0']--;
			ans.push_back(s2[j]);
			if (j == m) j = fail[j];
		}
		else
		{
			break;
		}
	}
	while (cnt[0]--) ans.push_back('0');
	while (cnt[1]--) ans.push_back('1');
	puts(ans.c_str());
	return 0;
}