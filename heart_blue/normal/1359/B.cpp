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
const int N = 1e3 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, a, b;
		dp[0] = 0;
		scanf("%d%d%d%d", &n, &m, &a, &b);
		dp[1] = a;
		for (int i = 2; i < N; i++)
			dp[i] = min(dp[i - 1] + a, dp[i - 2] + b);
		string str;
		int ans = 0;
		while (n--)
		{
			string str;
			cin >> str;
			str.push_back('*');
			int cnt = 0;
			for (auto& c : str)
			{
				if (c == '.') cnt++;
				else
				{
					ans += dp[cnt];
					cnt = 0;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}