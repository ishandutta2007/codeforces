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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> vp[N];
int tot[N];
int col[N];
int res[N];
int sons[N];
int dif = 0;
int ans = -1;
void dfs(int x, int fa = -1)
{
	sons[x] = 1;
	int flag = 0;
	res[x] = 1;
	for (auto &y : vp[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		sons[x] += sons[y];
		if (col[x] != col[y]) flag = 1;
		if (res[y] == 0)
		{
			res[x] = 0;
		}
	}
	if (!res[x]) return;
	if (flag) res[x] = 0;
	map<int, int> m;
	for (auto &y : vp[x])
	{
		if (y == fa) continue;
		m[col[y]] += sons[y];
	}
	m[col[x]]++;
	if (m.size() + 1 < dif) return;
	int cnt = 0;
	for (auto &p : m)
	{
		if (tot[p.first] > p.second)
		{
			cnt++;
		}
	}
	if (cnt > 1) return;
	if (cnt == 1 && dif - m.size() == 0) ans = x;
	if (cnt == 0 && dif - m.size() <= 1) ans = x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vp[x].push_back(y);
		vp[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) cin >> col[i], tot[col[i]]++;
	for (int i = 1; i < N; i++) if (tot[i]) dif++;
	dfs(1);
	if (ans == -1) puts("NO");
	else printf("YES\n%d\n", ans);
	return 0;
}