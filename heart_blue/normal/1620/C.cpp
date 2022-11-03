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
const int N = 2e3 + 10;
char str[N];
int cnt[N];
LL tot[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		LL x;
		scanf("%d%d%lld", &n, &k, &x);
		x--;
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++)
		{
			if (str[i] == 'a') cnt[i] = 0;
			else cnt[i] = k;
			if (str[i] == str[i - 1])
			{
				cnt[i] += cnt[i - 1];
				cnt[i - 1] = 0;
			}
		}
		tot[n + 1] = 1;
		for (int i = n; i >= 1; i--)
		{
			if (tot[i + 1] > INF * INF / (cnt[i] + 1)) tot[i] = INF * INF;
			else tot[i] = tot[i + 1] * (cnt[i] + 1);
		}
		for (int i = 1; i <= n; i++)
		{
			int o = x / tot[i + 1];
			if (str[i] == 'a') putchar('a');
			while (o-- > 0) putchar('b');
			x %= tot[i + 1];
		}
		puts("");
	}
	return 0;
}