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
const int N = 1e5 + 10;
LL len[N];
void solve(int& x, LL& pos, int n)
{
	if (x == n)
	{
		putchar('1');
		pos++;
		return;
	}
	if (pos > len[x])
	{
		x++;
		return;
	}
	else
	{
		int key = pos - len[x - 1];
		if (key & 1)
		{
			printf("%d ", x);
		}
		else
		{
			int res = key / 2 + x;
			printf("%d ", res);
		}
		pos++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	len[1] = 1;

	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			len[i] = len[i - 1] + (n - i) * 2;
		}
		len[n] = len[n - 1] + 1;
		LL l, r;
		scanf("%lld%lld", &l, &r);
		int cur = 1;
		while (l <= r)
			solve(cur, l, n);
		puts("");
	}
	return 0;
}