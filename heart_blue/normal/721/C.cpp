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
const int N = 5e3 + 10;
int dp[N][N];
bool vis[N][N];
short pre[N][N];
vector<pair<int, int>> vp[N];
typedef pair<int, pair<int, int>> Pair;
priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0x3f);
	MEM(vis, 0);
	MEM(pre, -1);
	dp[1][1] = 1;
	int n, m, t;
	cin >> n >> m >> t;
	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		vp[x].push_back({ y,w });
	}
	pq.push({ 0,{1,1} });
	while (!pq.empty())
	{
		auto p = pq.top(); pq.pop();
		int x, o;
		tie(x, o) = p.second;
		int tm = p.first;
		if (vis[x][o]) continue;
		vis[x][o] = 1;
		for (auto &p1 : vp[x])
		{
			int y, w;
			tie(y, w) = p1;
			if (tm + w > t) continue;
			if (tm + w < dp[y][o + 1])
			{
				dp[y][o + 1] = tm + w;
				pq.push({ tm + w,{y,o + 1} });
				pre[y][o + 1] = x;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dp[n][i] <= t)
		{
			ans = i;
		}
	}
	cout << ans << endl;
	vector<int> path;
	int o = ans;
	int x = n;
	while (pre[x][o] != -1)
	{
		path.push_back(x);
		x = pre[x][o];
		o--;
	}
	path.push_back(1);
	reverse(path.begin(), path.end());
	for (auto &x : path) cout << x << ' ';
	return 0;
}