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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
int deg[N];
pair<int, int> vp[N];
vector<int> pre[N];
bool check(int x)
{
	for (auto &y : pre[x])
	{
		if (deg[y] == 1) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	set<int> s;
	int n;
	cin >> n;
	map<pair<int, int>, int> mp;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		mp[{x, y}] = i;
		vp[i] = { x,y };
	}
	for (int i = 0; i < n; i++)
	{
		int x, y;
		tie(x, y) = vp[i];
		for (int o = -1; o <= 1; o++)
		{
			int ox = x + o;
			int oy = y + 1;
			if (mp.count({ ox,oy }))
			{
				int pos = mp[{ox, oy}];
				deg[pos]++;
				pre[i].push_back(pos);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (check(i))
			s.insert(i);
	}
	int o = 0;
	LL ans = 0;
	while (!s.empty())
	{
		int x;
		if (o == 0) x = *s.rbegin();
		else x = *s.begin();
		s.erase(x);
		o ^= 1;
		ans = (ans*n + x) % INF;
		deg[x] = 0;
		for (auto &y : pre[x])
			deg[y]--;
		int ox, oy;
		tie(ox, oy) = vp[x];
		mp.erase({ ox,oy });
		for (int i = -2; i <= 2; i++)
		{
			if (mp.count({ ox + i, oy }))
			{
				int pos = mp[{ox + i, oy}];
				if (!check(pos))
					s.erase(pos);
			}
		}
		for (int i = -1; i <= 1; i++)
		{
			if (mp.count({ ox + i,oy - 1 }))
			{
				int pos = mp[{ox + i, oy - 1}];
				if (check(pos))
					s.insert(pos);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}