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
const int N = 1e3 + 10;
LL getans(LL x1, LL x2, LL d)
{
	if (x1 < 0) x1 = -x1, x2 = -x2;
	if (x1 < x2) swap(x1, x2);
	LL o = (x1 + d - 1) / d;
	x1 -= d * o;
	x2 -= d * o;
	swap(x1, x2);
	return x2 / d - x1 / d;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	cout << max(getans(x1 + y1, x2 + y2, a * 2), getans(x1 - y1, x2 - y2, b * 2)) << endl;
	return 0;
}