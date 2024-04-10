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
vector<pair<int, int>> v[N];
vector < tuple <int, int, int>> vp;
int depth[N];
int sons[N];
double tot = 0;
int n;
LL sum(LL x)
{
	return x*(x - 1)*(x - 2);
}
void dfs(int x, int fa = -1)
{
	sons[x] = 1;
	depth[x] = 1;
	if (fa != -1) depth[x] += depth[fa];
	for (auto &p : v[x])
	{
		int y, w;
		tie(y, w) = p;
		if (y == fa) continue;
		dfs(y, x);
		sons[x] += sons[y];
		tot += 1.0*(sum(n) - sum(sons[y]) - sum(n - sons[y]))*w * 2;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		vp.push_back({ x,y,w });
		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
	}
	dfs(1);
	int q;
	cin >> q;
	while (q--)
	{
		int o, w;
		cin >> o >> w;
		o--;
		int x, y, w1;
		tie(x, y, w1) = vp[o];
		if (depth[x] < depth[y]) swap(x, y);
		tot -= 1.0*(sum(n) - sum(sons[x]) - sum(n - sons[x]))*2*(w1-w);
		get<2>(vp[o]) = w;
		printf("%.15f\n", tot *1.0 / n / (n - 1) / (n - 2));
	}
	return 0;
}