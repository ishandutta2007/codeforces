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
const int N = 2e5 + 10;
int flag[N][2];
LL ans[N][2];
int a[N];
int n;
pair<int, LL> dfs(int x, int o)
{
	if (x <= 0 || x > n) return { -1,0 };
	if (x == 1) return { 1,0 };
	if (flag[x][o]) return { flag[x][o],ans[x][o] };
	int &f = flag[x][o] = 1;
	LL &res = ans[x][o] = 0;
	if (o == 0)
	{
		tie(f, res) = dfs(x + a[x], 1);
		res += a[x];
	}
	else
	{
		tie(f, res) = dfs(x - a[x], 0);
		res += a[x];
	}
	return { f,res };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 2; i <= n; i++) cin >> a[i];
	MEM(flag, 0);
	for (int i = 2; i <= n; i++)
	{
		dfs(i, 0);
		dfs(i, 1);
	}
	for (int i = 1; i < n; i++)
	{
		int f;
		LL res;
		tie(f, res) = dfs(i + 1, 1);
		if (f == 1) puts("-1");
		else printf("%lld\n", res + i);
	}
	return 0;
}