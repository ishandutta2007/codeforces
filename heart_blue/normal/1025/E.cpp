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
const int N = 7e2 + 10;
vector<tuple<int, int, int, int>> ans, tmp;
typedef  pair<pair<int, int>, pair<int, int>> Node;
int a[N];
int flag1[4][4];
int flag2[4][4];
void check(int n, int m)
{
	if (n > 2) return;
	if (n == 1)
	{
		puts("0");
		exit(0);
	}
	tmp.emplace_back(1, 1, 1, 2);
	tmp.emplace_back(1, 1, 2, 1);
	tmp.emplace_back(1, 2, 1, 1);
	tmp.emplace_back(1, 2, 2, 2);
	tmp.emplace_back(2, 1, 2, 2);
	tmp.emplace_back(2, 1, 1, 1);
	tmp.emplace_back(2, 2, 2, 1);
	tmp.emplace_back(2, 2, 2, 2);
	for (int i = 0; i < m; i++)
	{
		int x, y, dx, dy;
		cin >> x >> y;
		flag1[x][y] = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, dx, dy;
		cin >> x >> y;
		flag2[x][y] = i + 1;
	}

	while (1)
	{
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				tot += flag1[i][j] == flag2[i][j];
			}
		}
		if (tot == 4)
		{
			break;
		}
		random_shuffle(tmp.begin(), tmp.end());
		int x, y, dx, dy;
		tie(x, y, dx, dy) = tmp.back();
		if (flag1[x][y] && flag1[dx][dy] == 0)
		{
			swap(flag1[x][y], flag1[dx][dy]);
			ans.emplace_back(x, y, dx, dy);
		}
	}
	printf("%d\n", ans.size());
	for (auto &p : ans)
	{
		int x, y, dx, dy;
		tie(x, y, dx, dy) = p;
		printf("%d %d %d %d\n", x, y, dx, dy);
	}
	exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	check(n, m);
	vector < pair<pair<int, int>, pair<int, int>>> vp(m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		vp[i].first = { x,y };
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		vp[i].second = { x,y };
	}
	sort(vp.begin(), vp.end());
	int L = 1, R = n;
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		if (vp[i].first.first == 1)
		{
			int y = vp[i].first.second;
			while (y > L)
			{
				ans.push_back({ 1,y,1,y - 1 });
				y--;
			}
			vp[i].first = { 1,L++ };
			continue;
		}
		if (vp[i].first.first == 2 && flag == 0)
		{
			flag = 1;
			int j = i;
			while (j <= m && vp[j].first.first == 2) j++;
			j--;
			int l = i;
			int r = j;
			while (l <= r)
			{
				swap(vp[l++], vp[r--]);
			}
		}
		int x, y;
		tie(x, y) = vp[i].first;
		while (x > 2)
		{
			ans.push_back({ x,y,x - 1,y });
			x--;
		}
		while (y < R)
		{
			ans.push_back({ x,y,x,y + 1 });
			y++;
		}
		while (y > R)
		{
			ans.push_back({ x, y, x, y - 1 });
			y--;
		}
		ans.push_back({ x,y,x - 1,y });
		vp[i].first = { 1,R-- };
	}
	sort(vp.begin(), vp.end(), [](Node &node1, Node &node2)->bool
	{
		if (node1.second != node2.second) return node1.second < node2.second;
		return node1.first < node1.first;
	});
	//reverse(vp.begin(), vp.end());
	while (!vp.empty() && vp.back().second.first > 3)
	{
		auto node = vp.back();
		vp.pop_back();
		int x, y, dx, dy;
		tie(x, y) = node.first;
		tie(dx, dy) = node.second;
		ans.push_back({ x,y,x + 1,y });
		x++;
		while (y < dy)
		{
			ans.emplace_back(x, y, x, y + 1);
			y++;
		}
		while (y > dy)
		{
			ans.emplace_back(x, y, x, y - 1);
			y--;
		}
		while (x < dx)
		{
			ans.emplace_back(x, y, x + 1, y);
			x++;
		}
	}
	R = n;
	if (!vp.empty()) reverse(vp.begin(), vp.end());
	for (auto &node : vp)
	{
		int x, y;
		tie(x, y) = node.first;
		if (x < 3)
		{
			ans.emplace_back(x, y, x + 1, y);
			x++;
		}
		while (y < R)
		{
			ans.emplace_back(x, y, x, y + 1);
			y++;
		}
		while (y > R)
		{
			ans.emplace_back(x, y, x, y - 1);
			y--;
		}
		while (x < 3)
		{
			ans.emplace_back(x, y, x + 1, y);
			x++;
		}
		node = make_pair(make_pair(x, y), node.second);
		R--;
	}
	int pre = 10;
	//reverse(vp.begin(), vp.end());
	for (auto &node : vp)
	{
		if (node.second.first == 3) continue;
		if (node.second.first != pre)
		{
			pre = node.second.first;
			R = n;
		}
		int x, y;
		tie(x, y) = node.first;
		while (x > pre)
		{
			ans.emplace_back(x, y, x - 1, y);
			x--;
		}
		while (y < R)
		{
			ans.emplace_back(x, y, x, y + 1);
			y++;
		}
		node.first = { x,y };
		R--;
	}
	if (!vp.empty()) reverse(vp.begin(), vp.end());
	for (auto &node : vp)
	{
		int x, y;
		int dx, dy;
		tie(x, y) = node.first;
		tie(dx, dy) = node.second;
		while (y > dy)
		{
			ans.emplace_back(x, y, x, y - 1);
			y--;
		}
	}
	printf("%d\n", ans.size());
	for (auto &p : ans)
	{
		int x, y, dx, dy;
		tie(x, y, dx, dy) = p;
		printf("%d %d %d %d\n", x, y, dx, dy);
	}
	return 0;
}