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
int solve(int &a, int &b, int val)
{
	int o = min(a, b);
	a -= o;
	b -= o;
	return val * o;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int x1, y1, z1;
		int x2, y2, z2;
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;
		int ans = 0;
		ans += solve(z1, y2, 2);
		solve(z1, z2, 0);
		solve(x1, z2, 0);
		ans += solve(y1, z2, -2);
		printf("%d\n", ans);
	}
	return 0;
}