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
const int N = 5e3 + 10;
int dp[N];
int flag[N];
int l[N], r[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0);
	MEM(flag, 0);
	MEM(l, 0x3f);
	MEM(r, 0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		l[a[i]] = min(i, l[a[i]]);
		r[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int o = i;
		dp[i] = dp[i - 1];
		int cur = i;
		int sum = 0;
		while (o >= 1)
		{
			int xorsum = 0;
			for (int j = cur; j >= o; j--)
			{
				if (r[a[j]] > i)
				{
					o = 1;
					sum = 0;
					xorsum = 0;
					break;
				}
				if (flag[a[j]] != i) xorsum ^= a[j], flag[a[j]] = i;
				o = min(o, l[a[j]]);
			}
			sum += xorsum;
			o--;
			cur = o;
			dp[i] = max(dp[i], dp[o] + sum);
		}
	}
	cout << dp[n] << endl;
	return 0;
}