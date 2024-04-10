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
const int N = 3e5 + 10;
struct Node
{
	int x, y, pos;
	bool operator < (const Node &node)
	{
		return x - y < node.x - node.y;
	}
	void init(int pos)
	{
		scanf("%d%d", &x, &y);
		this->pos = pos;
	}
};
Node a[N];
LL sumx[N];
LL sumy[N];
LL ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		a[i].init(i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sumx[i] = sumx[i - 1] + a[i].x;
		sumy[i] = sumy[i - 1] + a[i].y;
	}
	for (int i = 1; i <= n; i++)
	{
		ans[a[i].pos] = 1LL * (i - 1)*a[i].y + sumx[i - 1] + 1LL * (n - i)*a[i].x + sumy[n] - sumy[i];
	}
	sort(a + 1, a + n + 1, [](Node &node1, Node &node2)->bool
	{
		return node1.pos < node2.pos;
	});
	while (m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		LL sum = min(a[u].x + a[v].y, a[u].y + a[v].x);
		ans[u] -= sum;
		ans[v] -= sum;
	}
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}