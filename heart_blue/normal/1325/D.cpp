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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
void solve(LL u, LL w)
{
	if (u & w) return;
	LL a = w | u, b = w;
	puts("2");
	printf("%lld %lld\n", a, b);
	exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL u, v;
	cin >> u >> v;
	if (u == v)
	{
		if (u == 0) puts("0");
		else
		{
			puts("1");
			printf("%lld\n", u);
		}
		return 0;
	}
	if ((u ^ v) & 1) puts("-1"), exit(0);
	LL w = v - u;
	if (w < 0) puts("-1"), exit(0);
	w /= 2;
	solve(u, w);
	puts("3");
	printf("%lld %lld %lld", u, w, w);
	return 0;
}