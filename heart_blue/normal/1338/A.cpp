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
LL a[N];
LL b[N];
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
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for (int i = 1; i <= n; i++) b[i] = a[i];
		b[n + 1] = INF * INF;
		int ans = 34;
		for (int o = 34; o >= 0; o--)
		{
			for (int i = 1; i <= n; i++) b[i] = a[i];
			b[n + 1] = INF * INF;
			int flag = 1;
			for (int i = n; i >= 1; i--)
			{
				if (b[i] > b[i + 1])
				{
					flag = 0;
					break;
				}
				for (int j = o - 1; j >= 0; j--)
				{
					if (b[i] + (1LL << j) <= b[i + 1])
						b[i] += 1LL << j;
				}
			}
			if (flag) ans = o;
		}
		printf("%d\n", ans);
	}
	return 0;
}