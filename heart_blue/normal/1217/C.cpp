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
const int N = 2e5 + 10;
char str[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		for (int i = 1; i <= n; i++)
		{
			sum[i] = sum[i - 1] + (str[i] - '0');
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int o = 0;
			for (int j = i; j >= 1; j--)
			{
				if (i - j >= 30) break;
				if (str[j] == '0') continue;
				o |= 1 << (i - j);
				int l = i - o;
				if (l < 0) break;
				if (sum[j - 1] - sum[l]) continue;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}