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
const int N = 3e5 + 10;
int flag[N];
set<int> s[N];
int a[N];
int pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == a[n]) continue;
		if (y == a[n])
		{
			flag[x] = 1;
		}
		s[x].emplace(y);
	}
	int ans = n;
	for (int i = n - 1; i > 0; i--)
	{
		if (flag[a[i]])
		{
			int cnt = 0;
			for (auto& x : s[a[i]])
			{
				if (pos[x] < i) continue;
				if (pos[x] >= ans) continue;
				cnt++;
			}
			if (cnt != ans - i - 1)
				flag[a[i]] = 0;
			else
			{
				for (int j = i; j < ans; j++)
				{
					int x = a[j], y = a[j + 1];
					swap(a[j], a[j + 1]);
					swap(pos[x], pos[y]);
				}
				ans--;
			}
		}
	}
	printf("%d\n", n - ans);
	return 0;
}