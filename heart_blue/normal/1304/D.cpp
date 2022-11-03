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
int ans1[N];
int ans2[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d%s", &n, str + 2);
		fill(flag, flag + n + 1, 0);
		fill(ans1, ans1 + n + 1, 0);
		fill(ans2, ans2 + n + 1, 0);
		str[1] = '>';
		int cur = 1;
		for (int i = n; i >= 1; i--)
		{
			if (str[i] == '>')
			{
				while (flag[cur]) cur++;
				int ptr = i;
				while (ptr <= n && ans1[ptr] == 0)
				{
					ans1[ptr++] = cur;
					flag[cur++] = 1;
				}
			}
		}
		cur = n;
		fill(flag, flag + n + 1, 0);
		for (int i = n; i > 1; i--)
		{
			if (str[i] == '<')
			{
				ans2[i] = cur;
				flag[cur--] = 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (ans2[i] == 0)
			{
				ans2[i] = cur--;
			}
		}
		for (int i = 1; i <= n; i++) printf("%d%c", ans1[i], " \n"[i == n]);
		for (int i = 1; i <= n; i++) printf("%d%c", ans2[i], " \n"[i == n]);
	}
	return 0;
}