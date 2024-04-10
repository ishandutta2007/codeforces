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
const int N = 2e3 + 100;
struct Node
{
	int t, d, p;
	int pos;
	void init(int i)
	{
		cin >> t >> d >> p;
		pos = i;
	}
	bool operator < (Node &node)
	{
		return d < node.d;
	}
};
Node a[N];
pair<int, int> pre[N][N];
int dp[N][N];
int dfs(int pos, int cur)
{
	if (cur < 0) return -INF;
	if (dp[pos][cur] >= 0) return dp[pos][cur];
	if (pos == 0) return 0;
	int &tmp = dp[pos][cur] = 0;
	for (int i = 1; i <= pos; i++)
	{
		if (tmp < dfs(i - 1, min(cur, a[i].d - 1) - a[i].t) + a[i].p)
		{
			pre[pos][cur] = { i - 1, min(cur, a[i].d - 1) - a[i].t };
			tmp = dfs(i - 1, min(cur, a[i].d - 1) - a[i].t) + a[i].p;
		}
	}
	return tmp;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0xaf);
	MEM(pre, -1);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i].init(i);
	}
	sort(a + 1, a + n + 1);
	cout << dfs(n, 2050) << endl;
	int pos = n, cur = 2050;
	vector<int> ans;
	while (pre[pos][cur].first != -1)
	{
		tie(pos, cur) = pre[pos][cur];
		ans.push_back(a[pos + 1].pos);
	}
	if (!ans.empty()) reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}