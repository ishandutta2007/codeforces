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
const int N = 5e5 + 10;
LL powmod(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % INF;
		b >>= 1;
		a = a * a % INF;
	}
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, x;
		scanf("%d%d", &n, &x);
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x & 1) cnt1++;
			else cnt0++;
		}
		int ans = 0;
		for (int i = 0; i <= min(cnt0, x); i++)
		{
			if (x - i > cnt1) continue;
			if ((x - i) & 1) ans = 1;
		}
		if (ans) puts("YES");
		else puts("NO");
	}
	return 0;
}