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
const int N = 2e3 + 10;
int a[N][N];
vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		vp.push_back({ x, i });
	}
	sort(vp.rbegin(), vp.rend());
	MEM(a, 0x3f);
	int inf = 0x3f3f3f3f;
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		a[x][y] = min(a[x][y], c);
	}
	LL ans = 0;
	for (int i = 1; i < n; i++)
	{
		int minv = inf;
		for (int j = 0; j < i; j++)
		{
			int y = vp[i].second;
			int x = vp[j].second;
			minv = min(minv, a[x][y]);
		}
		if (minv == inf)
		{
			ans = -1;
			break;
		}
		ans += minv;
	}
	cout << ans << endl;
	return 0;
}