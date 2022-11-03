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
int n, m, s;
pair<int, int> a[N];
tuple<int, int, int> b[N];
int ans[N];
bool check(int x)
{
	int cur = m;
	LL cost = 0;
	typedef pair<int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	int ptr = n;
	while (cur > 0)
	{
		while (ptr > 0)
		{
			int lvl, c, pos;
			tie(lvl, c, pos) = b[ptr];
			if (lvl >= a[cur].first)
			{
				pq.push({ c,pos });
				ptr--;
			}
			else break;
		}
		if (pq.empty())
		{
			return false;
		}
		int c, pos;
		tie(c, pos) = pq.top();
		pq.pop();
		if (cost + c > s) return false;
		cost += c;
		for (int i = max(0, cur - x) + 1; i <= cur; i++)
		{
			ans[a[i].second] = pos;
		}
		cur -= x;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> get<0>(b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> get<1>(b[i]);
		get<2>(b[i]) = i;
	}
	sort(a + 1, a + m + 1);
	sort(b + 1, b + n + 1);
	int res = 0;
	int l = 1, r = m;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	if (res == 0) puts("NO");
	else
	{
		puts("YES");
		check(res);
		for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
	}
	return 0;
}