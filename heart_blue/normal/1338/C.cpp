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
const int N = 3e3 + 10;
int flag[N];
int a[] = { 0,
1,2 ,3	,
4,8 ,12	,
5,10, 15,
6,11, 13,
7,9 ,14	,
};
int offset[][3] =
{
16,32,48,
17,34,51,
18,35,49,
19,33,50,
20,40,60,
21,42,63,
22,43,61,
23,41,62,
24,44,52,
25,46,55,
26,47,53,
27,45,54,
28,36,56,
29,38,59,
30,39,57,
31,37,58,
};
void output(int b)
{
	string s;
	while (b)
	{
		s.push_back(b % 2 + '0');
		b /= 2;
	}
	reverse(s.begin(), s.end());
	printf(s.c_str());
	putchar(' ');
}
LL check(LL cnt)
{
	int d[4] = { 0,3,1,2 };
	LL res = 0;
	LL o = 1;
	while (cnt)
	{
		res += d[cnt % 4] * o;
		o *= 4;
		cnt /= 4;
	}
	return res;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	/*for (int i = 1; i < N; i++)
	{
		if (flag[i]) continue;
		int ok = 0;
		for (int j = i + 1; j < N; j++)
		{
			if (flag[j]) continue;
			if (flag[i ^ j]) continue;
			if ((i ^ j) >= N) break;
			flag[i] = 1, flag[j] = 1, flag[i ^ j] = 1;
			output(i);
			output(j);
			output(i ^ j);
			puts("");
			break;

		}
	}*/
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			offset[i][j] -= 16 * (j + 1);
		}
	}
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL n;
		scanf("%lld", &n);
		if (n <= 15) printf("%d\n", a[n]);
		else
		{
			n -= 16;
			LL cur = 16;
			int cnt = 2;
			while (n >= cur * 3)
			{
				cnt++;
				n -= cur * 3;
				cur *= 4;
			}
			LL key = cur;
			int oo = n % 48;
			LL ans1 = cur + n / 3;
			LL ans3 = check(n / 3) + cur * 3;
			LL ans2 = ans1 ^ ans3;
			LL ans[] = { ans1,ans2,ans3 };
			printf("%lld\n", ans[n % 3]);

		}
	}
	return 0;
}