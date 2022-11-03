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
const int N = 4e5 + 10;
int a[10];
int sum[10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		int ans = n * 7;
		for (int i = 1; i <= 7; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
		for (int i = 1; i <= 7; i++)
		{
			for (int j = i; j <= 7; j++)
			{
				if (sum[j] - sum[i - 1] == n)
				{
					ans = min(ans, j - i + 1);
					break;
				}
			}
		}
		int tot = sum[7];
		for (int i = 1; i <= 7; i++)
		{
			int tot = n - sum[7] + sum[i - 1];
			if (tot <= 0) continue;
			int d = tot / sum[7];
			if (d > 0) d--;
			tot -= d * sum[7];
			int res = 7 - i + 1 + d * 7;
			int o = 1;
			while (tot)
			{
				tot -= a[o++];
				res++;
				if (o > 7) o = 1;
			}
			ans = min(ans, res);
		}
		printf("%d\n", ans);
	}
	return 0;
}