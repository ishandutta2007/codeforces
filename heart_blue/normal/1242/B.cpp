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
const int N = 2e5 + 10;
vector<int> v[N];
set<int> s;
void dfs(int x)
{
	s.erase(x);
	for (int i = 0; i + 1 < v[x].size(); i++)
	{
		int l = v[x][i];
		int r = v[x][i + 1];
		while (1)
		{
			auto iter = s.upper_bound(l);
			if (iter == s.end()) break;
			int x = *iter;
			if (x >= r) break;
			dfs(x);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) s.insert(i);
	for (int i = 1; i <= n; i++)
	{
		v[i].push_back(0);
		v[i].push_back(i);
		v[i].push_back(n + 1);
		sort(v[i].begin(), v[i].end());
	}
	while (!s.empty())
	{
		dfs(*s.begin());
		ans++;
	}
	printf("%d\n", ans - 1);
	return 0;

}