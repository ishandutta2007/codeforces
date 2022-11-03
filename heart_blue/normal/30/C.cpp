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
const int N = 2e3 + 10;
struct Node
{
	double p;
	int t, x, y;
	void init()
	{
		scanf("%d%d%d%lf", &x, &y, &t, &p);
	}
	bool operator < (const Node& node) const
	{
		return t < node.t;
	}
} a[N];
double dp[N];
bool check(Node& node1, Node& node2)
{
	LL dx = node1.x - node2.x;
	LL dy = node1.y - node2.y;
	LL dt = abs(node1.t - node2.t);
	return dx * dx + dy * dy <= dt * dt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i].init();
	sort(a + 1, a + n + 1);
	double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 0;
		for (int j = 1; j < i; j++)
		{
			if (check(a[i], a[j]))
				dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += a[i].p;
		ans = max(ans, dp[i]);
	}
	printf("%.15f\n", ans);
	return 0;
}