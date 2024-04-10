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
vector<pair<int, int>> vp[N];
int deg[N];
int n;
bool check(int x)
{
	MEM(deg, 0);
	for (int i = 1; i <= n; i++)
	{
		for (auto p : vp[i])
		{
			if (p.first >= x) break;
			deg[p.second]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) if (deg[i] == 0) q.push(i);
	while (!q.empty())
	{
		if (q.size() != 1)
		{
			return false;
		}
		int u = q.front();
		q.pop();
		for (auto p : vp[u])
		{
			if (p.first >= x) break;
			deg[p.second] --;
			if (deg[p.second] == 0)
			{
				q.push(p.second);
			}
		}
	}
	return true;
}
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		vp[x].push_back({ i,y });
	}
	int l = n - 1;
	int r = m;
	int ans = -1;
	while (l <= r)
	{
		int mid = (r + l) / 2;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}