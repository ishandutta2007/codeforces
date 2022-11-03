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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
set<int> vp[N];
queue<pair<int, int>> q;
int flag[N];
int col[N];
void recheck(int x, int y)
{
	flag[x] = 1;
	int cx = col[x], cy = col[y];
	if (cx == cy)
	{
		puts("-1");
		exit(0);
	}
	for (auto& val : vp[x])
	{
		if (vp[y].find(val) != vp[y].end()) col[val] = cx ^ cy;
		else col[val] = cy;
		q.emplace(x, val);
	}
}
void check(int x, int y)
{
	if (flag[x] == 0)
	{
		recheck(x, y);
	}
	if (flag[y] == 0)
	{
		recheck(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v.emplace_back(x, y);
		vp[x].insert(y);
		vp[y].insert(x);
	}
	for (auto& p : v)
	{
		int x, y;
		tie(x, y) = p;
		if (col[x]) continue;
		col[x] = 1, col[y] = 2;
		q.emplace(x, y);
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			check(x, y);
		}
	}
	int cnt[5] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		cnt[col[i]]++;
	}
	if (cnt[1] + cnt[2] + cnt[3] != n 
		|| cnt[1] == 0 
		|| cnt[2] == 0 
		|| cnt[3] == 0 
		|| 1LL * cnt[1] * cnt[2] + 1LL * cnt[2] * cnt[3] + 1LL * cnt[3] * cnt[1] != v.size())
		puts("-1"), exit(0);
	for (auto& p : v)
	{
		int x, y;
		tie(x, y) = p;
		if ((col[x] != col[y]) ^ (vp[x].find(y) != vp[x].end()))
			puts("-1"), exit(0);
	}
	for (int i = 1; i <= n; i++) cout << col[i] << ' ';

	return 0;
}