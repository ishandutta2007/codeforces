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
const int N = 1e3 + 10;
int flag[N][N];
int a[N];
vector<int> v[N];
void solve(int n)
{
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			flag[a[i]][a[j]]++;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(flag, 0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		solve(n);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (flag[i][j] == k)
				v[i].push_back(j);
		}
	}
	queue<int> q;
	int in[N];
	MEM(in, 0x3f);
	int dis[N];
	MEM(dis, 0);
	for (int i = 1; i <= n; i++) q.push(i);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		in[x] = 0;
		for (auto &y : v[x])
		{
			if (dis[y] < dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				if (!in[y])
				{
					in[y] = 1;
					q.push(y);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dis[i]);
	cout << ans + 1 << endl;
	return 0;
}