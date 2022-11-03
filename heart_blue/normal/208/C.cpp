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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N][N];
int n;
int flag[N];
pair<LL, LL> ans[N];
void floyd()
{
	for (int i = 1; i <= n; i++) a[i][i] = 0;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}
pair<LL, LL> dfs(int x)
{
	if (ans[x].first != -1) return ans[x];
	//cout << x << endl;
	LL ans1 = 0, ans2 = 0;
	if (x == n) ans1++;
	for (int i = 1; i <= n; i++)
	{
		if (a[x][i] == 1 && a[1][x] + 1 == a[1][i])
		{
			LL a1, a2;
			tie(a1, a2) = dfs(i);
			ans1 += a1;
			ans2 += a2;
		}
	}
	if (flag[x]) swap(ans1, ans2);
	return ans[x] = { ans1,ans2 };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m;
	cin >> n >> m;
	MEM(a, 0x3f);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	double res = 0;
	floyd();
	for (int i = 1; i <= n; i++)
	{
		MEM(ans, 0xff);
		flag[i] = 1;
		LL a1, a2;
		tie(a1, a2) = dfs(1);
		double alpha = 2;
		if (i == 1 || i == n) alpha = 1;
		res = max(res, alpha*a2 / (a1 + a2));
		flag[i] = 0;
	}
	printf("%.15f\n", res);
	return 0;
}