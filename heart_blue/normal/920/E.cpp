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
set<int> s;
vector<int> v[N];
int cnt = 0;
void dfs(int x)
{
	if (s.find(x) == s.end()) return;
	s.erase(x);
	cnt++;
	for (int i = 0; i + 1 < v[x].size(); i++)
	{
		int y = *s.upper_bound(v[x][i]);
		if (y >= v[x][i + 1]) continue;
		dfs(y);
		i--;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
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
		v[i].push_back(0);
		v[i].push_back(n + 1);
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 1; i <= n + 1; i++) s.insert(i);

	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		dfs(i);
		if (cnt > 0) ans.push_back(cnt);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}