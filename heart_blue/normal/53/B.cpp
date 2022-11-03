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
const int N = 2e2 + 10;
LL w, h;

void check()
{
	pair<LL, LL> ans = { 0LL, 0LL };
	for (LL lo = 1; lo <= w; lo <<= 1)
	{
		LL d = (lo * 4 + 4) / 5, u = lo * 5 / 4;
		if (h < d) continue;
		ans = max(ans, make_pair(min(u, h) * 1LL * lo, min(u, h)));
	}
	for (LL lo = 1; lo <= h; lo <<= 1)
	{
		LL d = (lo * 4 + 4) / 5, u = lo * 5 / 4;
		if (w < d) continue;
		ans = max(ans, make_pair(min(u, w) * 1LL * lo, lo));
	}
	cout << ans.second << ' ' << ans.first / ans.second << endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> h >> w;
	check();
	return 0;
}