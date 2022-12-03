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
const int N = 2e5 + 10;
map<pair<int, int>, pair<int, int>> ans;
map<pair<int, int>, int> mc;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp(n);
	for (auto& p : vp)
	{
		scanf("%d%d", &p.first, &p.second);
		mc[p] = 1;
	}
	queue<pair<int, int>> q;
	for (auto& p : vp)
	{
		auto [x, y] = p;
		for (int i = 0; i < 4; i++)
		{
			if (!mc.count({ x + dx[i],y + dy[i] }))
			{
				ans[{x, y}] = { x + dx[i],y + dy[i] };
				q.emplace(x, y);
				break;
			}
		}
	}
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int px = x + dx[i];
			int py = y + dy[i];
			if (!mc.count({ px,py })) continue;
			if (ans.count({ px,py })) continue;
			ans[{px, py}] = ans[{x, y}];
			q.emplace(px, py);
		}
	}
	for (auto& p : vp)
	{
		auto [x, y] = ans[p];
		printf("%d %d\n", x, y);
	}
	return 0;
}