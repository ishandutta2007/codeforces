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
const int N = 2e3 + 10;
vector<int> v[N*100];
int a[N][N];
int n, m;
int sum[N];
int ans[N*100];
struct Node
{
	int type;
	int x, y;
} qr[N*100];
void dfs(int o)
{
	int pre = 0;
	int x = qr[o].x;
	int y = qr[o].y;
	if (qr[o].type <= 2) pre = a[x][y];
	if (qr[o].type == 1) a[x][y] = 1;
	if (qr[o].type == 2) a[x][y] = 0;
	if (qr[o].type == 3)
	{
		for (int i = 1; i <= m; i++) a[x][i] ^= 1;
	}
	sum[x] = 0;
	for (int i = 1; i <= m; i++) sum[x] += a[x][i];
	ans[o] = 0;
	for (int i = 1; i <= n; i++) ans[o] += sum[i];
	for (auto &nxt : v[o])
	{
		dfs(nxt);
	}
	if (qr[o].type <= 2) a[x][y] = pre;
	if (qr[o].type == 3)
	{
		for (int i = 1; i <= m; i++) a[x][i] ^= 1;
	}
	sum[x] = 0;
	for (int i = 1; i <= m; i++) sum[x] += a[x][i];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin >> n >> m >> q;
	qr[0].type = qr[0].x = qr[0].y = 0;
	int pre = 0;
	for (int i = 1; i <= q; i++)
	{
		int op, x, y = 0;
		cin >> op >> x;
		if (op <= 2) cin >> y;
		if (op == 4) pre = x, x = 0;
		v[pre].push_back(i);
		qr[i] = Node{ op,x,y };
		pre = i;
	}
	dfs(0);
	for (int i = 1; i <= q; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}