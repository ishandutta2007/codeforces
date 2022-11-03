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
int lminv[N], lmaxv[N];
int rminv[N], rmaxv[N];
char str[N];
int sum[N];
void refrain(int n, int a[N])
{
	a[n + 1] = 0;
	int r = 0;
	for (int i = n; i >= 1; i--)
	{
		str[i] ^= '+' ^ '-';
		if (str[i] == '-') r = max(0, r - 1);
		else r++;
		a[i] = r;
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
		int o = 0;
		int n, q;
		scanf("%d%d", &n, &q);
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++)
		{
			if (str[i] == '+') o++;
			else o--;
			sum[i] = o;
			lmaxv[i] = lmaxv[i - 1];
			lminv[i] = lminv[i - 1];
			if (o >= 0) lmaxv[i] = max(lmaxv[i], o);
			if (o <= 0) lminv[i] = max(lminv[i], -o);
		}
		refrain(n, rminv);
		refrain(n, rmaxv);
		while (q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			int minv = min(-lminv[l - 1], sum[l - 1] - rminv[r + 1]);
			int maxv = max(lmaxv[l - 1], sum[l - 1] + rmaxv[r + 1]);
			printf("%d\n", maxv - minv + 1);
		}
	}
	return 0;
}