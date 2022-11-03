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
const int N = 5e2 + 10;
int a[N][N];
vector<pair<int, int>> ans;
int floyd(int n)
{
	for (int i = 1; i <= n; i++) a[i][i] = 0;
	int ans = 0;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans = max(ans, a[i][j]);
		}
	}
	return ans;
}
void add(int i, int j)
{
	if (i > j) swap(i, j);
	a[i][j] = a[j][i] = 1;
	ans.emplace_back(i, j);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0x3f);
	int n;
	cin >> n;
	vector<int> v;
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 1) v.push_back(i);
		else vp.emplace_back(x, i);
	}
	if (vp.empty())
	{
		puts("NO");
		return 0;
	}
	if (vp.size() >= 2)
	{
		swap(vp[0], vp[vp.size() - 2]);
	}
	for (int i = 0; i + 1 < vp.size(); i++)
	{
		vp[i].first--;
		vp[i + 1].first--;
		add(vp[i].second, vp[i + 1].second);
	}
	if (vp.front().first > 0 && !v.empty())
	{
		vp.front().first--;
		add(vp.front().second, v.back());
		v.pop_back();
	}
	if (vp.back().first > 0 && !v.empty())
	{
		vp.back().first--;
		add(vp.back().second, v.back());
		v.pop_back();
	}
	for (auto& p : vp)
	{
		while (p.first && !v.empty())
		{
			add(p.second, v.back());
			v.pop_back();
			p.first--;
		}
	}
	if (!v.empty()) puts("NO"), exit(0);
	printf("YES %d\n", floyd(n));
	printf("%d\n", n - 1);
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}