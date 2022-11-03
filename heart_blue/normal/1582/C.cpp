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
const int N = 1e5 + 10;
int solve(string& str, char c)
{
	int l = 0, r = str.length() - 1;
	int ret = 0;
	while (l < r)
	{
		if (str[l] == str[r])
		{
			l++, r--;
			continue;
		}
		if (str[l] == c)
		{
			l++;
			ret++;
			continue;
		}
		if (str[r] == c)
		{
			r--;
			ret++;
			continue;
		}
		return INF;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		int ans = INF;
		for (char c = 'a'; c <= 'z'; c++)
		{
			ans = min(ans, solve(str, c));
		}
		if (ans == INF) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}