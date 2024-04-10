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
const int N = 2e2 + 10;
LL cnt1[N];
LL cnt2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		for (int o = 0; x >> o; o++)
		{
			if (x >> o & 1)
				cnt1[o]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		cnt2[x]++;
	}
	LL ans = 0;
	for (int i = 0; i <= 30; i++)
	{
		while (cnt2[i])
		{
			if (cnt1[i])
			{
				int o = min(cnt1[i], cnt2[i]);
				ans += o;
				cnt1[i] -= o;
				cnt2[i] -= o;
				continue;
			}
			int key = i;
			for (int j = i; j <= 30; j++)
			{
				if (cnt1[j])
				{
					key = j;
					break;
				}
			}
			if (key == i) break;
			for (int j = i; j < key; j++) cnt1[j]++;
			cnt1[i]++;
			cnt1[key]--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}