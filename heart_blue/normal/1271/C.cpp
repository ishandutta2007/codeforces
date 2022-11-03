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
const int N = 2e5 + 10;
int dx[] = { 1,1,1,-1,-1,-1,0,0 };
int dy[] = { 1,-1,0,1,-1,0,1,-1 };
pair<int, int> p[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, sx, sy;
	cin >> n >> sx >> sy;
	for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
	tuple<int, int, int> maxv = make_tuple(0, 0, 0);
	for (int o = 0; o < 8; o++)
	{
		int cnt = 0;
		int x = sx + dx[o];
		int y = sy + dy[o];
		if (x < 0 || y < 0) continue;
		if (x > 1e9 || y > 1e9) continue;
		for (int i = 1; i <= n; i++)
		{
			if (abs(p[i].first - sx) + abs(p[i].second - sy) ==
				abs(p[i].first - x) + abs(p[i].second - y) + abs(dx[o]) + abs(dy[o]))
				cnt++;
		}
		maxv = max(maxv, make_tuple(cnt, x, y));
	}
	int ans, x, y;
	tie(ans, x, y) = maxv;
	cout << ans << endl;
	cout << x << ' ' << y << endl;
	return 0;
}