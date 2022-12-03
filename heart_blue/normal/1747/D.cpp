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
const int N = 2e5 + 10;
int pre[N];
int sum0[N];
int sumx[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	map<int, int> mc[2];
	mc[0][0] = 0;
	MEM(pre, -1);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		sumx[i] = sumx[i - 1] ^ x;
		if (mc[(i & 1) ^ 1].count(sumx[i]))
			pre[i] = mc[(i & 1) ^ 1][sumx[i]];
		mc[i & 1][sumx[i]] = i;
		sum0[i] = sum0[i - 1] + (x == 0);
	}
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (sum0[r] - sum0[l - 1] == r - l + 1)
		{
			puts("0");
			continue;
		}
		if (sumx[r] != sumx[l - 1])
		{
			puts("-1");
			continue;
		}
		if (r - l <= 1)
		{
			puts("-1");
			continue;
		}
		if ((r - l) & 1)
		{
			if (a[l] == 0 || a[r] == 0) puts("1");
			else if (pre[r] >= l - 1) puts("2");
			else puts("-1");
		}
		else
			puts("1");
	}
	return 0;
}