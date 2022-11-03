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
const int N = 1e5 + 10;
map<int, map<int, int>> mp;
vector<int> ans;
void dfs(int x, int fa = -1)
{
	ans.push_back(x);
	for (auto &p : mp[x])
	{
		int y = p.first;
		if (y == fa) continue;
		dfs(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		mp[x][y] = mp[y][x] = 1;
	}
	int key = -1;
	for (auto &p : mp)
	{
		if (p.second.size() == 1)
		{
			key = p.first;
			break;
		}
	}
	dfs(key);
	for (auto &x : ans) cout << x << ' ';
	return 0;
}