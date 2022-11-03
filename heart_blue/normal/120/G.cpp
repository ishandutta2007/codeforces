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
const int N = 2e2 + 10;
int a[N][2][2];
vector<string> ans[N];
int cost[N][N];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0][0] >> a[i][0][1] >> a[i][1][0] >> a[i][1][1];
	}
	queue<tuple<int, int, string>> q;
	int sz;
	cin >> sz;
	for (int i = 1; i <= sz; i++)
	{
		int h;
		string str;
		cin >> str >> h;
		q.emplace(i, h, str);
	}
	int cur = 1, o = 0;
	int T = t;
	while (!q.empty())
	{
		int id;
		int h;
		string s;
		tie(id, h, s) = q.front();
		if (T > 0)
		{
			int x = max(1, h - a[cur][o][0] - a[cur][o ^ 1][1] - cost[cur][id]);
			if (T >= x)
			{
				ans[cur].emplace_back(s);
				T -= x;
				q.pop();
				continue;
			}
			T = min(T, x);
			cost[cur][id] += T;
			q.pop();
			q.emplace(id, h, s);
		}
		T = t;
		cur++;
		if (cur > n) cur = 1, o ^= 1;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d", ans[i].size());
		for (auto& s : ans[i])
			printf(" %s", s.c_str());
		puts("");
	}
	return 0;
}