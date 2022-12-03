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
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		string str;
		cin >> str;
		int len = str.length();
		int sum = 0;
		map<int, int> mc;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '1')
				mc[i % m] = 1, sum++;
			int res = 0;
			if (i >= m) res = dp[i - m];
			if (i >= m && str[i - m] == '1')
				sum--;
			if (sum > 0) res++;
			dp[i] = res;
			printf("%d%c", res + mc.size(), " \n"[i + 1 == len]);
		}
	}
	return 0;
}