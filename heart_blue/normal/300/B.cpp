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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int vis[N];
int cnt[N];
int a[N][N];
int ans[N];
vector<int> v[N];
int n;
bool check(int fa)
{
	list<int> l;
	l.push_back(fa);
	vis[fa] = fa;
	while (!l.empty())
	{
		int x = l.front();
		l.pop_front();
		cnt[fa]++;
		for (int i = 1; i <= n; i++)
		{
			if (a[x][i] == 0) continue;
			if (vis[i]) continue;
			vis[i] = fa;
			l.push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == fa) v[fa].push_back(i);
	}
	if (cnt[fa] > 3) return false;
	else return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m;
	cin >> n >> m;
	MEM(a, 0);
	MEM(vis, 0);
	MEM(ans, 0);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		if (!check(i))
		{
			cout << -1 << endl;
			return 0;
		}
		if (cnt[i] == 1) cnt1++;
		if (cnt[i] == 2) cnt2++;
	}
	if (cnt1 < cnt2 || (cnt1-cnt2)%3 != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	int p = 1;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] != 1) continue;
		while (p <= n && cnt[p] != 2) p++;
		if (p > n) break;
		vis[i] = 0;
		cout << v[i][0] << ' ' << v[p][0] << ' ' << v[p][1] << endl;
		p++;
	}
	int c = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 1 && vis[i])
		{
			cout << i << ' ';
			c++;
			if (c % 3 == 0) cout << endl;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 3)
		{
			for (auto &x : v[i]) cout << x << ' ';
			cout << endl;
		}
	}
	return 0;
}