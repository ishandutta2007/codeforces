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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int b[N];
int dis[N];
pair<int, int> pre[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	queue<int> q;
	pre[0] = { -1,-1 };
	q.push(n);
	int last = n;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		int low = x - a[x];
		while (last > low)
		{
			last--;
			if (dis[last + b[last]]) continue;
			dis[last + b[last]] = dis[x] + 1;
			pre[last + b[last]] = { last,x };
			q.push(last + b[last]);
		}
	}
	if (pre[0].first == -1)
	{
		puts("-1");
		return 0;
	}
	vector<int> ans;
	int cur = 0;
	while (cur != n)
	{
		auto [x, y] = pre[cur];
		ans.push_back(x);
		cur = y;
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}