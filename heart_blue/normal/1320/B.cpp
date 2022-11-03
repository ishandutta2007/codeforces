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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v1[N], v2[N];
int a[N];
int dis[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v1[x].push_back(y);
		v2[y].push_back(x);
	}
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) cin >> a[i];
	queue<int> q;
	q.push(a[k]);
	MEM(dis, 0x3f);
	dis[a[k]] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto& y : v2[x])
		{
			if (dis[y] > dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < k; i++)
	{
		if (dis[a[i]] != dis[a[i + 1]] + 1)
			ans1++;
		else
		{
			int x = a[i];
			int cnt = 0;
			for (auto& y : v1[x])
			{
				if (dis[x] == dis[y] + 1)
					cnt++;
			}
			if (cnt > 1)
				ans2++;
		}
	}
	ans2 += ans1;
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}