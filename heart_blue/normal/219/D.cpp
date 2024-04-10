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
vector<pair<int, int>> vp[N];
int ans[N];
int tot = 0;
void dfs(int x, int cur = 0, int fa = -1)
{
	ans[x] = cur;
	for (auto &p : vp[x])
	{
		int y, o;
		tie(y, o) = p;
		if (y == fa) continue;
		tot += o;
		dfs(y, cur + (o == 1 ? -1 : 1), x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(ans, 0);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vp[x].push_back({ y,0 });
		vp[y].push_back({ x,1 });
	}
	dfs(1);
	int minv = INF;
	for (int i = 1; i <= n; i++)
	{
		minv = min(minv, ans[i]);
	}
	cout << tot + minv << endl;
	for (int i = 1; i <= n; i++)
	{
		if (minv == ans[i])
			cout << i << ' ';
	}
	return 0;
}