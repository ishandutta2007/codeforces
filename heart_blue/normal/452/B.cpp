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
const int N = 1e6 + 10;
map<pair<int, int>, int> mp;
vector<pair<int, int>> vp;
int n, m;
void add(int x, int y, int dx, int dy)
{
	for (int i = x, o = 3; o >= 0 && i >= 0 && i <= n; i += dx, o--)
	{
		
		if (mp.count({ i,y })) continue;
		vp.push_back({ i,y });
		mp[{i, y}] = 1;
	}
	for (int j = y, o = 3; o >= 0 && j >= 0 && j <= m; j += dy, o--)
	{
		if (mp.count({ x,j })) continue;
		vp.push_back({ x,j });
		mp[{x, j}] = 1;
	}
}
double dis(pair<int,int> &p1, pair<int,int> &p2)
{
	int dx = p1.first - p2.first;
	int dy = p1.second - p2.second;
	return sqrt(dx*dx + dy*dy);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	add(0, 0, 1, 1);
	add(0, m, 1, -1);
	add(n, 0, -1, 1);
	add(n, m, -1, -1);
	int sz = vp.size();
	tuple<double, int, int, int, int> ans = { -1.0,0,0,0,0 };
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (i == j) continue;
			for (int k = 0; k < sz; k++)
			{
				if (k == i || k == j) continue;
				for (int t = 0; t < sz; t++)
				{
					if (t == i || t == j || t == k) continue;
					ans = max(ans,
					{ dis(vp[i],vp[j]) + dis(vp[j],vp[k]) + dis(vp[k],vp[t]),
						i,j,k,t });
				}
			}
		}
	}
	double e;
	int a, b, c, d;
	tie(e, a, b, c, d) = ans;
	int ar[4] = { a,b,c,d };
	for (int i = 0; i < 4; i++)
	{
		cout << vp[ar[i]].first << ' ' << vp[ar[i]].second << endl;
	}
	return 0;
}