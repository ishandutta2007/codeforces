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
		fill(cnt, cnt + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		for (int i = 1; i <= n; i++)
			cnt[i] += cnt[i - 1];
		int l = 1, r = n;
		int ans = n, x = 1, y = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int flag = 0;
			for (int i = mid; i <= n; i++)
			{
				if (cnt[i] - cnt[i - mid] >= n - cnt[i] + cnt[i - mid] + k)
				{
					flag = 1;
					x = i - mid + 1;
					y = i;
					break;
				}
			}
			if (flag) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		vector<pair<int, int>> v;
		v.emplace_back(x, y);
		for (int i = 1; i <= n; i++)
		{
			if (v.size() == k)
			{
				v.emplace_back(i, n);
				break;
			}
			int j = i;
			int cur = 0;
			while (j <= n)
			{
				if (a[j] >= x && a[j] <= y) cur++;
				else cur--;
				if (cur > 0) break;
				j++;
			}
			v.emplace_back(i, j);
			i = j;
		}
		for (auto [l, r] : v)
			printf("%d %d\n", l, r);
	}
	return 0;
}