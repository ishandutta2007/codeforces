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
tuple<int, int, int> ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double a1, b1, r1;
	double a2, b2, r2;
	cin >> a1 >> b1 >> r1;
	cin >> a2 >> b2 >> r2;
	double dx = a1 - a2;
	double dy = b1 - b2;
	double dis = sqrt(dx*dx + dy*dy);
	if (r1 < r2) swap(a1, a2), swap(b1, b2), swap(r1, r2);
	if (dis > r1 + r2)
	{
		printf("%.15f\n", (dis - r1 - r2)/2);
	}
	else if (dis < r1 - r2)
	{
		printf("%.15f\n", (r1 - r2 - dis)/2);
	}
	else printf("%.15f\n", 0.0);
	return 0;
}