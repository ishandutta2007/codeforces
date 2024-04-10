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
const int N = 1e3 + 10;
vector<int> v1[N], v2[N];
int a[N][N];
void refrain(vector<int>& v)
{
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			v1[i].push_back(a[i][j]);
			v2[j].push_back(a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) refrain(v1[i]);
	for (int i = 1; i <= m; i++) refrain(v2[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x = lower_bound(v1[i].begin(), v1[i].end(), a[i][j]) - v1[i].begin();
			int y = lower_bound(v2[j].begin(), v2[j].end(), a[i][j]) - v2[j].begin();
			printf("%d%c", max(x, y) + 1 + max(v1[i].size() - x - 1, v2[j].size() - y - 1), " \n"[j == m]);
		}
	}
	return 0;
}