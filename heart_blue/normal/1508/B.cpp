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
const int N = 2e5 + 10;
LL p[N];
int ans[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	p[0] = 1;
	p[1] = 1;
	for (int i = 2; i < N; i++)
	{
		p[i] = min(INF * INF, p[i - 1] * 2);
	}
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		LL k;
		scanf("%d%lld", &n, &k);
		if (n <= 62)
		{
			if (k > (1LL << (n - 1)))
			{
				puts("-1");
				continue;
			}
		}
		memset(flag, 0, sizeof(int) * (n + 1));
		int ptr = n - 1;
		int cur = 1;
		int pre = -INF;
		for (int i = 1; i <= n; i++)
		{
			while (flag[cur]) cur++;
			int pp = max(pre - 1, cur);
			while (flag[pp]) pp++;
			int ptr = n - i;
			while (k > p[ptr])
			{
				k -= p[ptr];
				ptr--;
				pp++;
				while (flag[pp]) pp++;
			}
			printf("%d ", pp);
			flag[pp] = 1;
			pre = pp;
		}
		puts("");
	}
	return 0;
}