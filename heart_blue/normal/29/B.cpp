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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l, d, v, g, r;
	cin >> l >> d >> v >> g >> r;
	double cost = 0;
	int cur = 0;
	while (1)
	{
		if (cur + v*g > d)
		{
			printf("%.14f\n", cost + 1.0*(l - cur) / v);
			break;
		}
		cost += g;
		cur += v*g;
		cur += v*r;
		cost += r;
		cur = min(cur, d);
	}
	return 0;
}