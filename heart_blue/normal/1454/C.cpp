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
int pre[N];
int ans[N];
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
		for (int i = 1; i <= n; i++) pre[i] = 0;
		for (int i = 1; i <= n; i++) ans[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (i - pre[x] > 1) ans[x]++;
			pre[x] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			if (pre[i] == 0) continue;
			if (pre[i] != n) ans[i]++;
		}
		int res = INF;
		for (int i = 1; i <= n; i++)
		{
			if (pre[i] == 0) continue;
			res = min(res, ans[i]);
		}
		printf("%d\n", res);

	}
	return 0;
}