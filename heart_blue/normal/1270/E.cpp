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
struct Point
{
	int x, y;
} a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].x += 1e7;
		a[i].y += 1e7;
	}
	vector<int> ans;
	while (1)
	{
		int cnt[4] = { 0,0,0,0 };
		for (int i = 1; i <= n; i++)
		{
			cnt[(a[i].x & 1) << 1 | (a[i].y & 1)]++;
		}
		if (cnt[0] == n || cnt[1] == n || cnt[2] == n || cnt[3] == n)
		{
			for (int i = 1; i <= n; i++)
			{
				a[i].x = (a[i].x + 1) / 2;
				a[i].y = (a[i].y + 1) / 2;
			}
			continue;
		}
		if (cnt[0] + cnt[3] == n || cnt[1] + cnt[2] == n)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i].x & 1)
					ans.push_back(i);
			}
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if ((a[i].x + a[i].y) & 1)
					ans.push_back(i);
			}
		}
		break;
	}
	printf("%d\n", ans.size());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}