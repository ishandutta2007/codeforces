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
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
int L[N], R[N];
int cnt[N];
void init()
{
	for (int i = 1; i < N; i++) cnt[i] = cnt[i >> 1] + (i & 1);
}
int check(int l1, int r1, int l2, int r2)
{
	l1 = max(l1, l2);
	r1 = min(r1, r2);
	return max(0, r1 - l1 + 1);
}
inline bool test(int mask, int o)
{
	return mask >> o & 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> L[i] >> R[i];
	}
	double ans = 0;
	int tot = (1 << n);
	for (int mid = 1; mid <= 10000; mid++)
	{
		int mask = 0;
		for (int i = 0; i < n; i++)
		{
			if (L[i] <= mid && mid <= R[i])
				mask |= 1 << i;
		}
		for (int s = mask; s; s = (s - 1)&mask)
		{
			for (int o1 = 0; o1 < n; o1++)
			{
				if (test(s, o1)) continue;
				LL cnt = check(mid + 1, INF, L[o1], R[o1]);
				for (int o2 = 0; o2 < n; o2++)
				{
					if (o1 == o2 || test(s, o2)) continue;
					cnt *= check(-INF, mid - 1, L[o2], R[o2]);
				}
				ans += 1.0*cnt * mid;
			}
			if (cnt[s] > 1)
			{
				LL cnt = 1;
				for (int o = 0; o < n; o++)
				{
					if (test(s, o)) continue;
					cnt *= check(-INF, mid - 1, L[o], R[o]);
				}
				ans += 1.0*cnt * mid;
			}
		}
	}
	for (int i = 0; i < n; i++) ans /= (R[i] - L[i] + 1);
	printf("%.15f\n", ans);
	return 0;
}