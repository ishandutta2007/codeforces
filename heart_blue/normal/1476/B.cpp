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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e4 + 10;
int a[N];
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
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		LL ans = 0;
		LL l = 0, r = INF * INF / 100;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			LL sum = mid + a[0];
			int flag = 1;
			for (int i = 1; i < n; i++)
			{
				if (100LL * a[i] > k * sum)
				{
					flag = 0;
					break;
				}
				sum += a[i];
			}
			if (flag) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}

	return 0;
}