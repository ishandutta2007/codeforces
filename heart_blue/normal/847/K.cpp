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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 6e2 + 10;
int cost[N][N];
map<string, int> ms;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b, k, f;
	cin >> n >> a >> b >> k >> f;
	int m = 0;
	int pre = 0;
	MEM(cost, 0);
	for (int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (!ms.count(s1)) ms[s1] = ++m;
		if (!ms.count(s2)) ms[s2] = ++m;
		int x = ms[s1], y = ms[s2];
		if (x == pre) cost[x][y] += b;
		else cost[x][y] += a;
		pre = y;
	}
	vector<int> v;
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = i + 1; j <= m; j++)
		{
			ans += cost[i][j] + cost[j][i];
			if (cost[i][j] + cost[j][i] > f)
			{
				v.push_back(cost[i][j] + cost[j][i] - f);
			}
		}
	}
	if (!v.empty()) sort(v.rbegin(), v.rend());
	for (auto &x : v)
	{
		if (k == 0) break;
		ans -= x;
		k--;
	}
	cout << ans << endl;
	return 0;
}