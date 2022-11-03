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
const int N = 3e5 + 10;
int a[N];
void check(int& l1, int& r1, int& l2, int& r2, int k, int d)
{
	if (k == d && l1 != -1 && l2 != -1)
	{
		l1 = 0, r1 = k;
		l2 = k, r2 = 0;
		return;
	}
	if (r1 == k)
	{
		l1 = 0, r1 = d;
		l2 = d, r2 = 0;
		return;
	}
	if (l1 != -1)
	{
		l1++, r1++;
		r1 = min(r1, k);
		if (l1 > d)
		{
			l1 = r1 = -1;
		}
		else
		{
			r1 = d;
		}
	}
	if (l2 != -1)
	{
		if (l2 == 0)
		{
			l2 = r2 = -1;
		}
		else
		{
			l2--, r2--;
			r2 = max(r2, 0);
			l2 = min(l2, d);
		}
	}
	int cnt = 5;
	while (cnt--)
	{
		if (r1 == k)
		{
			l2 = k;
			l1 = r2 = 0;
			break;
		}
		if (r2 == 0)
		{
			l1 = 0;
			r1 = max(r1, l2);
		}

	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k, len;
		scanf("%d%d%d", &n, &k, &len);
		int l1 = 0, r1 = k;
		int l2 = k, r2 = 0;
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x > len) flag = 0;
			if (flag == 0) continue;
			check(l1, r1, l2, r2, k, min(k, len - x));
		}
		if (l1 == -1 && l2 == -1) flag = 0;
		if (flag) puts("Yes");
		else puts("No");
	}
	return 0;
}