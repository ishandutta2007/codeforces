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
const int N = 2e6 + 10;
vector<int> v[N];
int len[N];
void dfs(int u, int depth)
{
	if (len[u] != -1) return;
	len[u] = depth;
	for (auto &x : v[u])
	{
		dfs(x, depth + 1);
	}
}
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
		v[x].push_back(y);
		v[y].push_back(x);
	}
	MEM(len, -1);
	dfs(1, 0);
	int maxv = -1;
	int key = -1;
	for (int i = 1; i <= n; i++)
	{
		if (maxv < len[i])
		{
			maxv = len[i];
			key = i;
		}
	}
	MEM(len, -1);
	dfs(key, 0);
	maxv = -1;
	for (int i = 1; i <= n; i++)
	{
		maxv = max(maxv, len[i]);
	}
	cout << maxv << endl;
	return 0;
}