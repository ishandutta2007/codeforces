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
const int N = 1e5 + 10;
set<int> s[N];
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (1LL * n * (n - 1) / 2 == m)
	{
		puts("NO");
		return 0;
	}
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		s[x].emplace(y);
		s[y].emplace(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (s[i].size() == n - 1) continue;
		int x = i;
		int y = i;
		for (int j = i + 1; j <= n; j++)
		{
			if (s[x].find(j) == s[x].end())
			{
				y = j;
				break;
			}
		}
		if (x == y) continue;
		a[x] = 1, a[y] = 2;
		b[x] = 1, b[y] = 1;
		int cur = 3;
		for (int i = 1; i <= n; i++)
		{
			if (i == x || i == y) continue;
			a[i] = b[i] = cur++;
		}
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d ", a[i]);
		puts("");
		for (int i = 1; i <= n; i++) printf("%d ", b[i]);
		return 0;
	}
	puts("NO");
	return 0;
}