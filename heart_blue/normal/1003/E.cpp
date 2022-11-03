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
const int N = 4e5 + 10;
int a[N];
int dis[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d, k;
	cin >> n >> d >> k;
	if (n < d + 1)
	{
		puts("NO");
		return 0;
	}
	if (d > 1)
	{
		if (k == 1)
		{
			puts("NO");
			return 0;
		}
	}
	vector<pair<int, int>> ans;
	for (int i = 1; i <= d; i++)
	{
		dis[i] = max(i - 1, d + 1 - i);
		ans.push_back({ i,i + 1 });
	}
	int cur = d + 2;
	for (int i = 2; i <= d; i++)
	{
		queue<int> q;
		for (int j = 3; cur <= n && j <= k; j++)
		{
			ans.push_back({ i,cur });
			q.push(cur);
			dis[cur++] = dis[i] + 1;
		}
		while (!q.empty() && cur <= n)
		{
			int x = q.front();
			q.pop();
			if (dis[x] == d) break;
			for (int j = 2; cur <= n && j <= k; j++)
			{
				ans.push_back({ x,cur });
				q.push(cur);
				dis[cur++] = dis[x] + 1;
			}
		}
	}
	if (cur <= n)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for (auto &p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}