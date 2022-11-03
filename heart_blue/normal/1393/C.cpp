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
const int N = 2e5 + 10;
vector<int> v1[N], v2[N];
int f[N];
int vis[N];
int ans[N];
void dfs1(int x, vector<int> v[N], int cnt = 0)
{
	if (vis[x]) return;
	if (f[x] == 1 && cnt == 1) return;
	if (f[x] == 1) cnt++;
	vis[x] = 1;
	ans[x] |= 1;
	for (auto& y : v[x])
	{
		dfs1(y, v, cnt);
	}
}
void dfs2(int x, vector<int> v[N])
{
	if (vis[x]) return;
	vis[x] = 1;
	ans[x] |= 2;
	if (f[x] == 1) return;
	for (auto& y : v[x])
	{
		dfs2(y, v);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		map<int, int> mc1, mc2;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			mc1[x]++;
		}
		for (auto& p : mc1)
		{
			mc2[p.second]++;
		}
		int maxv = mc2.rbegin()->first;
		int cnt = mc2.rbegin()->second;
		int rest = n - cnt;
		printf("%d\n", rest / (maxv - 1) - 1);
	}
	return 0;
}