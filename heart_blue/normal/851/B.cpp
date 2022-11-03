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
LL dis(LL ax, LL ay, LL bx, LL by)
{
	LL dx = ax - bx;
	LL dy = ay - by;
	return dx*dx + dy*dy;
}
LL cross(LL ax, LL ay, LL bx, LL by, LL cx, LL cy)
{
	return ax*by + bx*cy + cx*ay - ax*cy - bx*ay - cx*by;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if (dis(ax, ay, bx, by) == dis(bx, by, cx, cy) &&
		cross(ax, ay, bx, by, cx, cy) != 0)
		puts("Yes");
	else puts("No");
	return 0;
}