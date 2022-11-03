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
int a[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	int l = 1, r = n;
	int ans = 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		set<int> s;
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			sum[i] = sum[i - 1];
			if (a[i] >= mid) sum[i]++;
			else sum[i]--;
			if (i >= k)
			{
				s.insert(sum[i - k]);
				auto iter = s.lower_bound(sum[i]);
				if (iter != s.begin())
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}