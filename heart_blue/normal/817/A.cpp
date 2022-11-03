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
const int N = 3e4 + 10;
const int M = 5e2 + 10;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ax, bx, ay, by;
	cin >> ax >> ay >> bx >> by;
	int x, y;
	cin >> x >> y;
	int dx = abs(ax - bx);
	int dy = abs(ay - by);
	if (dx%x != 0 || dy%y != 0)
	{
		puts("NO");
		return 0;
	}
	if ((dx / x + dy / y) % 2 == 0) puts("YES");
	else puts("NO");
	return 0;
}