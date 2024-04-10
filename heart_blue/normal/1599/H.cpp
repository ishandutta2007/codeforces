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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int limit = 1e9;
int ask(int x, int y)
{
	x = min(x, limit);
	y = min(y, limit);
	cout << "? " << x << ' ' << y << endl;
	int ret;
	cin >> ret;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int dy1 = ask(1, 1);
	int dy2 = ask(1, limit);
	int ky = (1LL * limit - (dy2 - dy1) + 1) / 2;
	if (ask(1, ky) > ask(1, ky + 1)) ky++;
	int dx1 = ask(1, 1);
	int dx2 = ask(limit, 1);
	int kx = (1LL * limit - (dx2 - dx1) + 1) / 2;
	if (ask(kx, 1) > ask(kx + 1, 1)) kx++;
	int x, y, p, q;
	x = ask(1, ky) + 1;
	p = limit - ask(limit, ky);
	y = ask(kx, 1) + 1;
	q = limit - ask(kx, limit);
	cout << "! " << x << ' ' << y << ' ' << p << ' ' << q << endl;
	return 0;
}