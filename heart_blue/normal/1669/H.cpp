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
const int N = 3e2 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		MEM(cnt, 0);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			for (int o = 0; o <= 30; o++)
			{
				if (x >> o & 1)
					cnt[o]++;
			}
		}
		int ans = 0;
		for (int o = 30; o >= 0; o--)
		{
			if (k >= n - cnt[o])
			{
				k -= n - cnt[o];
				cnt[o] = n;
			}
			if (cnt[o] == n)
				ans |= 1 << o;
				
		}
		printf("%d\n", ans);
	}
	return 0;

}