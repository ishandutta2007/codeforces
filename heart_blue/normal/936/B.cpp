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
pair<int, int> pre[N][2];
int vis[N][2];
int sz[N];
int cnt[N];
bool dfs(int x)
{
	if (cnt[x] == 2) return true;
	for (auto &y : v[x])
	{
		cnt[x]++;
		if (dfs(y)) return true;
		cnt[x]--;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;
	MEM(pre, -1);
	MEM(vis, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> sz[i];
		for (int j = 1; j <= sz[i]; j++)
		{
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}
	int s;
	cin >> s;
	q.push({ s,1 });
	vis[s][1] = 1;
	while (!q.empty())
	{
		int x, o;
		tie(x, o) = q.front();
		q.pop();
		for (auto &y : v[x])
		{
			if (vis[y][o ^ 1]) continue;
			pre[y][o ^ 1] = { x,o };
			vis[y][o ^ 1] = 1;
			q.push({ y,o ^ 1 });
		}
		if (v[x].empty() && vis[x][0])
		{
			cout << "Win" << endl;
			vector<int> ans;
			int o = 0;
			while (pre[x][o].first != -1)
			{
				ans.push_back(x);
				tie(x, o) = pre[x][o];
			}
			ans.push_back(s);
			reverse(ans.begin(), ans.end());
			for (auto &x : ans) cout << x << ' ';
			return 0;
		}
	}
	if (dfs(s)) cout << "Draw" << endl;
	else cout << "Lose" << endl;
	return 0;
}