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
int fa[N];
int w[N];
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(fa, -1);
	MEM(w, 0);
	MEM(deg, 0);
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> vp;
	while (m--)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		fa[x] = y;
		deg[y]++;
		w[x] = cost;
	}
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] || fa[i] == -1) continue;
		int ans = INF;
		int x = i;
		do
		{
			ans = min(ans, w[x]);
			x = fa[x];
		} while (fa[x] != -1);
		vp.push_back({ i,x,ans });
	}
	cout << vp.size() << endl;
	for (auto &p : vp)
	{
		int x, y, cost;
		tie(x, y, cost) = p;
		printf("%d %d %d\n", x, y, cost);
	}
	return 0;
}