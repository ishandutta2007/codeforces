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
const int N = 2e3 + 10;
char str[N][N];
int solve(int x, int y, int n)
{
	int cnt = 2 * n + 10;
	queue<int> q;
	int sum = 0;
	int ret = 0;
	while (cnt--)
	{
		if (x >= n) x = 0;
		if (y >= n) y = 0;
		q.push(str[x][y] - '0');
		if (str[x][y] == '1') sum++;
		if (q.size() > n)
		{
			sum -= q.front();
			q.pop();
		}
		x++, y++;
		ret = max(ret, sum);
	}
	return ret;
}
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
		int ans = 0;
		int tot = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
			tot += count(str[i], str[i] + n, '1');
		}
		for (int i = 0; i < n; i++)
		{
			ans = max(ans, solve(0, i, n));
			ans = max(ans, solve(i, 0, n));
		}
		ans = tot - ans + n - ans;
		printf("%d\n", ans);
	}

	return 0;
}