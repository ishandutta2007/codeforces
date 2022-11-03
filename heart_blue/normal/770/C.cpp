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
const int N = 1e5 + 10;
vector<int> v1[N], v2[N];
vector<int> v;
int flag[N];
int deg[N];
int f[N];
bool check(int n)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0) q.push(i);
	}
	int cnt = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cnt += flag[x];
		for (auto &y : v1[x])
		{
			deg[y]--;
			if (deg[y] == 0) q.push(y);
		}
	}
	return cnt == v.size();
}
void refrain(int n)
{
	queue<int> q;
	for (auto &x : v) q.push(x);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto &y : v2[x])
		{
			if (f[y]) continue;
			f[y] = 1;
			q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) deg[i] = v1[i].size();
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		if (f[i] == 0)
		{
			for (auto &x : v2[i])
			{
				deg[x]--;
			}
		}
	}
}
void solve(int n)
{
	refrain(n);
	queue<int> q;
	for (int i = 1; i <= n; i++) if (flag[i] && deg[i] == 0) q.push(i);
	vector<int> ans;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		ans.push_back(x);
		for (auto &y : v2[x])
		{
			deg[y]--;
			if (deg[y] == 0) q.push(y);
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	v.resize(k);
	for (auto &x : v) cin >> x, flag[x] = 1;
	for (int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		deg[i] = m;
		while (m--)
		{
			int x;
			cin >> x;
			v1[x].push_back(i);
			v2[i].push_back(x);
		}
	}
	if (check(n)) solve(n);
	else cout << -1 << endl;
	return 0;
}