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
map<int, int> mc[N];
int vis[N];
vector<int> v;
void dfs(int x)
{
	vis[x] = 1;
	v.push_back(x);
	for (auto &p : mc[x])
	{
		if (vis[p.first]) continue;
		dfs(p.first);
		break;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		mc[x][y] = mc[y][x] = 1;
	}
	dfs(1);
	reverse(v.begin(), v.end());
	int x = v.front();
	while (!mc[x].count(v.back())) v.pop_back();
	cout << v.size() << endl;
	for (auto &x : v) cout << x << ' ';
	return 0;
}