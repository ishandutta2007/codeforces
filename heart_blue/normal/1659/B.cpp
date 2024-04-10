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
int ans[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		scanf("%s", str);
		fill(ans, ans + n, 0);
		int rest = k;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == '0')
			{
				if (k % 2 == 0)
				{
					if (rest > 0) rest--, ans[i] = 1;
				}
			}
			else
			{
				if (k % 2 == 1)
				{
					if (rest > 0) rest--, ans[i] = 1;
				}
			}
		}
		ans[n - 1] += rest;
		for (int i = 0; i < n; i++)
		{
			str[i] ^= (k - ans[i]) & 1;
		}
		puts(str);
		for (int i = 0; i < n; i++)
			printf("%d%c", ans[i], " \n"[i + 1 == n]);
	}
	return 0;
}