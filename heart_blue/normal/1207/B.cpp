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
const LL INF = 1e8 + 7;
const int N = 2e2 + 10;
int a[N][N];
int dx[] = { 0,0,1,1 };
int dy[] = { 0,1,0,1 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	map<pair<int, int>, int> mc;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			sum += a[i][j];
		}
	}
	vector<pair<int, int>> ans;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			int cnt = 0;
			for (int o = 0; o < 4; o++)
			{
				cnt += a[i + dx[o]][j + dy[o]];
			}
			if (cnt != 4) continue;
			ans.emplace_back(i, j);
			for (int o = 0; o < 4; o++)
			{
				mc[make_pair(i + dx[o], j + dy[o])] = 1;
			}
		}
	}
	if (mc.size() != sum) puts("-1"), exit(0);
	printf("%d\n", ans.size());
	for(auto &p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}