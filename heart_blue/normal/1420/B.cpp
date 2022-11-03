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
int cnt[30];
LL sum(LL x)
{
	return x * (x - 1) / 2;
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
		MEM(cnt, 0);
		while (n--)
		{
			int x;
			scanf("%d", &x);
			for (int i = 30; i >= 0; i--)
			{
				if (x >> i & 1)
				{
					cnt[i]++;
					break;
				}
			}
		}
		LL ans = 0;
		for (int i = 0; i < 30; i++)
			ans += sum(cnt[i]);
		printf("%lld\n", ans);
	}
	return 0;
}