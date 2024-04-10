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
const int N = 1e2 + 10;
const int M = 1e4 + 10;
char str[N][M];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	MEM(str, ' ');
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	int l = 1, r = 1;
	LL ans = 0;
	int d = 1;
	int cur = l;
	for (int i = 1; i < n; i++)
	{
		int cnt = 0;
		while (cnt <= 10)
		{
			if (str[i + 1][cur] == '.')
			{
				l = r = cur;
				ans++;
				cnt = 0;
				break;
			}
			if (d == 1)
			{
				if (cur != r)
				{
					ans += r - l;
					cnt++;
					cur = r;
				}
				if (str[i][cur + 1] == '.')
				{
					r = ++cur;
					ans++;
					cnt = 0;
				}
				else if (str[i][cur + 1] == '+')
				{
					str[i][cur + 1] = '.';
					d = -1;
					ans++;
					cnt = 0;
				}
				else
				{
					d = -1;
					ans++;
					cnt++;
				}
			}
			else
			{
				if (cur != l)
				{
					ans += r - l;
					cnt++;
					cur = l;
				}
				if (str[i][cur - 1] == '.')
				{
					l = --cur;
					ans++;
					cnt = 0;
				}
				else if (str[i][cur - 1] == '+')
				{
					str[i][cur - 1] = '.';
					d = 1;
					ans++;
					cnt = 0;
				}
				else
				{
					d = 1;
					ans++;
					cnt++;
				}
			}
		}
		if (cnt >= 10)
		{
			puts("Never");
			return 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}