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
const int N = 1e3 + 10;
int v1[N];
int v2[N];
LL dp[N][N];
int flag[N * 100];
int getnum(string str)
{
	reverse(str.begin(), str.end());
	if (str.empty()) return 1;
	return stoi(str);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 0, m = 0;
	int a;
	scanf("%d", &a);
	string str;
	cin >> str;
	str = "+" + str;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] != 'a') continue;
		int* v;
		int* sz;
		int p = 0;
		if (i >= 3 && flag[i - 1] == 0 && flag[i - 2] == 0 && str[i - 1] == '+' && str[i - 2] == '+')
		{
			v = v2, p = i - 3, sz = &m;
			flag[i - 1] = flag[i - 2] = flag[i] = 1;
		}
		else
		{
			v = v1, p = i - 1, sz = &n;
			flag[i] = flag[i + 1] = flag[i + 2] = 1;
		}
		if (str[p] == '-') v[++ * sz] = -1;
		else if (str[p] == '+') v[++ * sz] = 1;
		else
		{
			p--;
			string key = "";
			while (p >= 0)
			{
				key.push_back(str[p]);
				if (!isdigit(str[p])) break;
				p--;
			}
			v[++ * sz] = getnum(key);
		}
	}
	sort(v1 + 1, v1 + n + 1);
	sort(v2 + 1, v2 + m + 1);
	MEM(dp, 0xcf);
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (i + j + a) * v1[i + 1]);
			if (j < m) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + (i + j + a + 1) * v2[j + 1]);
		}
	}
	printf("%lld\n", dp[n][m]);

	return 0;
}