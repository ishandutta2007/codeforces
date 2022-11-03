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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	/*
	x = v/u*y + k;
	*/
	int n, w, u, v;
	cin >> n >> w >> v >> u;
	double l = 1e18, r = -1e18;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		double k = x - 1.0*v*y / u;
		l = min(l, k);
		r = max(r, k);
	}
	if (r < 1e-10 || l > -1e-10) printf("%.15f\n", 1.0*w / u);
	else printf("%.15f\n", r / v + 1.0*w / u);
	return 0;
}