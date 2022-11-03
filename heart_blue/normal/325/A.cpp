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
const int N = 5e2 + 10;
int a[N];
int flag[N][N];
map<int, int> mc[2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < 4 * n; i++)
	{
		cin >> a[i];
		a[i] *= 2;
	}
	for (int i = 0; i < 4 * n; i++)
	{
		mc[i & 1][a[i]] = 1;
		mc[i & 1][a[i] - 1] = 1;
		mc[i & 1][a[i] + 1] = 1;
	}
	for (int i = 0; i < 2; i++)
	{
		int o = 0;
		for (auto &p : mc[i])
		{
			p.second = o++;
		}
	}
	for (int o = 0; o < n * 4; o += 4)
	{
		int l = mc[0][a[o]], r = mc[0][a[o + 2]];
		int u = mc[1][a[o + 1]], d = mc[1][a[o + 3]];
		for (int i = l; i <= r; i++)
		{
			for (int j = u; j <= d; j++)
			{
				flag[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < mc[0].size(); i++)
	{
		for (int j = 0; j < mc[1].size(); j++)
		{
			cnt += flag[i][j];
		}
	}
	int x = mc[0].rbegin()->first - mc[0].begin()->first - 1;
	int y = mc[1].rbegin()->first - mc[1].begin()->first - 1;
	if (x == y && (mc[0].size() - 2)*(mc[1].size() - 2) == cnt) puts("YES");
	else puts("NO");
	return 0;
}