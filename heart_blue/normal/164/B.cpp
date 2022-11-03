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
const int N = 1e6 + 10;
int a[N * 2];
int pos[N];
list<int> q[N];
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
		pos[x] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
		a[i + m] = a[i];
	}
	for (int i = 1; i <= 2 * m; i++)
	{
		a[i] = pos[a[i]];
	}
	int ans = 0;
	for (int i = 1; i <= 2 * m; i++)
	{
		int x = a[i];
		if (x == 0) continue;
		int y = x - 1;
		if (y == 0) y = n;
		q[x].clear();
		q[x].swap(q[y]);
		q[x].push_back(i);
		while (!q[x].empty() && i - q[x].front() >= m)
			q[x].pop_front();
		int sz = q[x].size();
		ans = max(ans, sz);
	}
	printf("%d\n", ans);
	return 0;
}