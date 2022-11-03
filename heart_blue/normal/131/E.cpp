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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int cnt[N];
vector<pair<int, int>> v1[N], v2[N], v3[N * 2 + 10], v4[N * 2 + 10];
void check(vector<pair<int, int>> v[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (v[i].empty()) continue;
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j + 1 < v[i].size(); j++)
		{
			cnt[v[i][j].second]++;
			cnt[v[i][j + 1].second]++;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		v1[x].push_back({ y,i });
		v2[y].push_back({ x,i });
		v3[x + y].push_back({ x,i });
		v4[x - y + N].push_back({ x,i });
	}
	check(v1, N);
	check(v2, N);
	check(v3, N * 2 + 10);
	check(v4, N * 2 + 10);
	int ans[10];
	MEM(ans, 0);
	for (int i = 1; i <= m; i++) ans[cnt[i]]++;
	for (int i = 0; i <= 8; i++) printf("%d ", ans[i]);
	return 0;
}