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
LL t[N];
int x[N];
bool check(LL l, LL r, LL pos)
{
	if (l > r) swap(l, r);
	return l <= pos && pos <= r;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld%d", &t[i], &x[i]);
		}
		t[n + 1] = INF * INF;
		int o = 0;
		LL cur = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int j = i;
			o = 0;
			if (x[i] > cur) o = 1;
			if (x[i] < cur) o = -1;
			while (j <= n)
			{
				LL l = cur;
				LL r = cur + o * min(t[j + 1] - t[j], abs(x[i] - cur));
				cur = r;
				if (check(l, r, x[j])) cnt++;
				if (check(l, r, x[i]))
				{
					break;
				}
				j++;
			}
			cur = x[i];
			i = j;
		}
		printf("%d\n", cnt);
	}
	return 0;
}