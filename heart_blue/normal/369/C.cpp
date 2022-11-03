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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<pair<int, int>> v[N];
vector<int> ans;
int dfs(int x, int o, int fa = -1)
{
	int ret = 0;
	for (auto &p : v[x])
	{
		int y, w;
		tie(y, w) = p;
		if (y == fa) continue;
		ret |= dfs(y, w, x);
	}
	if (ret == 0 && o == 1)
	{
		ans.push_back(x);
		ret = 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back({ y,w - 1 });
		v[y].push_back({ x,w - 1 });
	}
	dfs(1, 0);
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}