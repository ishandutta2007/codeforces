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
const int N = 1e5 + 10;
vector<int> v[N];
int deg[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[y].push_back(x);
		deg[x]++;
	}
	queue<int> q[2];
	for (int i = 0; i < n; i++)
	{
		if (deg[i] == 0)
			q[a[i]].push(i);
	}
	int o = 1;
	int ans = 0;
	while (!q[0].empty() || !q[1].empty())
	{
		o ^= 1;
		if (q[o].empty()) continue;
		ans += o;
		while (!q[o].empty())
		{
			int x = q[o].front();
			q[o].pop();
			for (auto& y : v[x])
			{
				if (deg[y]-- == 1)
					q[a[y]].push(y);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}