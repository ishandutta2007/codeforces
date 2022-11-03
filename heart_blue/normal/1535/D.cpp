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
int son[N][2];
int fa[N];
char str[N];
int ans[N];
void build(int k)
{
	scanf("%s", str + 1);
	int tot = 1 << k;
	for (int i = 1; i <= tot; i++)
	{
		ans[i] = 1;
	}
	int cur = 1;
	for (int i = 1; i < tot; i++)
	{
		son[i + tot][0] = cur;
		son[i + tot][1] = cur + 1;
		fa[cur] = i + tot;
		fa[cur + 1] = i + tot;
		int res1 = ans[cur];
		int res2 = ans[cur + 1];
		cur += 2;
		if (str[i] == '0')
			ans[i + tot] = res1;
		else if (str[i] == '1')
			ans[i + tot] = res2;
		else
			ans[i + tot] = res1 + res2;
	}
}
void solve(int pos, int tot)
{
	while (pos)
	{
		int res1 = ans[son[pos][0]];
		int res2 = ans[son[pos][1]];
		if (str[pos - tot] == '0')
			ans[pos] = res1;
		else if (str[pos - tot] == '1')
			ans[pos] = res2;
		else
			ans[pos] = res1 + res2;
		pos = fa[pos];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	scanf("%d", &k);
	build(k);
	int q;
	scanf("%d", &q);
	int tot = 1 << k;
	while (q--)
	{
		int x;
		char c;
		scanf("%d %c", &x, &c);
		str[x] = c;
		solve(x + tot, tot);
		printf("%d\n", ans[2 * tot - 1]);
	}
	return 0;
}