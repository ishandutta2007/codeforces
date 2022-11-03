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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL n, m;
LL getans(LL x, LL dx, LL o)
{
	if (dx == 0) return INF;
	if (dx < 0) return (x - 1) / -dx;
	else return (o - x) / dx;
}
LL moveto(LL &x, LL &y, LL dx, LL dy)
{
	LL cnt = min(getans(x, dx, n), getans(y, dy, m));
	x += dx*cnt;
	y += dy*cnt;
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	LL x, y;
	cin >> x >> y;
	int q;
	cin >> q;
	LL ans = 0;
	while (q--)
	{
		LL dx, dy;
		cin >> dx >> dy;
		ans += moveto(x, y, dx, dy);
	}
	cout << ans << endl;
	return 0;
}