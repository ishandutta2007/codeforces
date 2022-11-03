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
const int N = 3e3 + 10;
pair<int, int> p[N];
vector<int> v[N];
void dfs(int x, int fa = 0)
{
	if (p[x].first)
	{
		v[x].pop_back();
		return;
	}
	p[x] = make_pair(int(INF), int(INF));
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
	}
	sort(v[x].begin(), v[x].end(), [](int x, int y)->bool
		{
			return p[x] < p[y];
		});
	for (int i = 0; i + 1 < v[x].size(); i++)
	{
		if (p[v[x][i]].second > p[v[x][i + 1]].first)
		{
			puts("-1"), exit(0);
		}
	}
	if (v[x].back() == fa) v[x].pop_back();
	p[x] = make_pair(p[v[x].front()].first, p[v[x].back()].second);
}
void output(int x, int fa = 0)
{
	for (auto& y : v[x])
	{
		printf("%d ", x);
		output(y, x);
	}
	printf("%d ", x);
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
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int cnt = 1;
	int x;
	while (cin >> x)
	{
		p[x] = make_pair(cnt, cnt);
		cnt++;
	}
	dfs(1);
	output(1);
	return 0;
}