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
int cnt[N][2];
int w[N];
LL ans = 0;
int n;
void dfs1(int x, int p = -1)
{
	cnt[x][0] = 1;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs1(y, x);
		cnt[x][0] += cnt[y][1];
		cnt[x][1] += cnt[y][0];
	}
}
void dfs2(int x, int cnt0 = 0, int cnt1 = 0, int p = -1)
{
	LL tot = (cnt0 + cnt1 + (cnt0 + 1 - cnt1)*(cnt[x][0] + cnt[x][1])) % INF;
	for (auto y : v[x])
	{
		if (y == p) continue;
		int r = n - (cnt[y][0] + cnt[y][1]);
		tot += 1LL * (cnt[y][1] - cnt[y][0])*r%INF;
		dfs2(y, cnt1 + cnt[x][1] - cnt[y][0], cnt0 + cnt[x][0] - cnt[y][1], x);
	}
	tot %= INF;
	ans = (ans + tot * w[x]) % INF;
	if (ans < 0) ans += INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1);
	dfs2(1);
	cout << ans << endl;
	return 0;
}