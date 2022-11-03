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
const int N = 1e2 + 10;
map<LL, pair<int, pair<int, int>>> m1, m2;
int dx[] = { 3,2,2,1,1,1,1,1 };
int dy[] = { 1,1,1,1,3,2,2,1 };
void check(int a, int b, map<LL, pair<int, pair<int, int>>> &m)
{
	map<pair<int, int>, int> mp;
	mp[{a, b}] = 0;
	queue<pair<int, int>> q;
	q.push({ a,b });
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		int o = mp[{x, y}];
		if (!m.count(1LL * x*y)) m[1LL * x*y] = { o,{x,y} };
		m[1LL * x*y] = min(m[1LL * x*y], { o,{x,y} });
		for (int i = 0; i < 8; i += 2)
		{
			if (x%dx[i] == 0 && y %dy[i] == 0)
			{
				int tx = x / dx[i] * dx[i + 1];
				int ty = y / dy[i] * dy[i + 1];
				if (!mp.count({ tx,ty }))
				{
					q.push({ tx,ty });
					mp[{tx, ty}] = o + 1;
				}
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<string> vs = { "S", "M", "L", "XL","XXL" };
	int pref[5][5] = {
		0,1,2,3,4,
		1,2,0,3,4,
		2,3,1,4,0,
		3,4,2,1,0,
		4,3,2,1,0,
	};
	map<string, int> ms;
	for (int i = 0; i < vs.size(); i++) ms[vs[i]] = i;
	int a[5];
	int n = 5;
	for (int i = 0; i < n; i++) cin >> a[i];
	int q;
	cin >> q;
	while (q--)
	{
		string str;
		cin >> str;
		int o = ms[str];
		for (int i = 0; i < 5; i++)
		{
			if (a[pref[o][i]] > 0)
			{
				a[pref[o][i]]--;
				puts(vs[pref[o][i]].c_str());
				break;
			}
		}
	}
	return 0;
}