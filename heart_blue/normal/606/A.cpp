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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c;
	int x, y, z;
	cin >> a >> b >> c;
	cin >> x >> y >> z;
	int l = 0;
	int r = 0;
	if (a > x) l += (a - x) / 2;
	else r += x - a;
	if (b > y) l += (b - y) / 2;
	else r += y - b;
	if (c > z) l += (c - z) / 2;
	else r += z - c;
	if (l >= r) puts("YES");
	else puts("NO");
	return 0;
}