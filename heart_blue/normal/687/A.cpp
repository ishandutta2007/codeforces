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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> v[N];
int color[N];
int flag = 0;
void dfs(int x, int c)
{
	if (color[x] > 0)
	{
		if (color[x] != c) flag = 1;
		return;
	}
	color[x] = c;
	for (auto &y : v[x])
	{
		dfs(y, 3 - c);
		if (flag) return;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(color, 0);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (color[i]) continue;
		dfs(i, 1);
	}
	vector<int> v[2];
	if (flag)
	{
		cout << -1 << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			v[color[i] - 1].push_back(i);
		}
		for (int i = 0; i < 2; i++)
		{
			cout << v[i].size() << endl;
			for (auto &x : v[i]) cout << x << ' ';
			cout << endl;
		}
	}
	return 0;
}