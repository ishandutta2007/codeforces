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
const int N = 3e5 + 10;
vector<int> v[N];
queue<int> q;
vector<pair<int, int>> vp;
int flag[N];
int dis[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, d;
	scanf("%d%d%d", &n, &k, &d);
	MEM(dis, 0x3f);
	while (k--)
	{
		int x;
		scanf("%d", &x);
		flag[x] = x;
		q.push(x);
		dis[x] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp.push_back({ x,y });
		v[x].push_back(y);
		v[y].push_back(x);
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (dis[x] == d) continue;
		for (auto &y : v[x])
		{
			if (flag[y]) continue;
			flag[y] = flag[x];
			dis[y] = dis[x] + 1;
			q.push(y);
		}
	}
	int tot = 0;
	for (auto &p : vp)
	{
		if (flag[p.first] != flag[p.second]) tot++;
	}
	printf("%d\n", tot);
	for (int i = 0; i < vp.size(); i++)
	{
		int x, y;
		tie(x, y) = vp[i];
		if (flag[x] != flag[y]) printf("%d ", i + 1);
	}
	return 0;
}