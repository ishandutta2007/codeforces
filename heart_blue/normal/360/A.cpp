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
const int N = 5e3 + 10;
LL a[N];
int op[N];
int l[N];
int r[N];
int d[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(a, 0x01);
	LL inf = 1LL * m*5e7;
	for (int i = 1; i <= m; i++)
	{
		cin >> op[i] >> l[i] >> r[i] >> d[i];
		if (op[i] == 1)
		{
			for (int j = l[i]; j <= r[i]; j++)
			{
				a[j] += d[i];
			}
		}
		else
		{
			for (int j = l[i]; j <= r[i]; j++)
			{
				a[j] = min(a[j], 1LL*d[i]);
			}
		}
	}
	int flag = 1;
	for (int i = m; i >= 1; i--)
	{
		if (op[i] == 1)
		{
			for (int j = l[i]; j <= r[i]; j++) a[j] -= d[i];
		}
		else
		{
			LL maxv = a[l[i]];
			for (int j = l[i]; j <= r[i]; j++) maxv = max(maxv, a[j]);
			if (maxv != d[i])
			{
				flag = 0;
				break;
			}
		}
	}
	if (flag)
	{
		puts("YES");
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > inf) a[i] = 0;
			printf("%lld ", a[i]);
		}
	}
	else puts("NO");
	return 0;
}