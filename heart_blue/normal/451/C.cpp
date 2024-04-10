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
const int N = 2e5 + 10;
LL n, k;
bool check(LL d1, LL d2)
{
	if (d1 < 0 || d2 < 0) return false;
	if (d1 + 2 * d2 > k) return false;
	if (k % 3 != (d1 + 2 * d2) % 3) return false;
	LL o = 2 * d1 + d2;
	LL r = n - k - o;
	return (r >= 0 && r % 3 == 0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		LL d1, d2;
		cin >> n >> k >> d1 >> d2;
		if (check(d1, d2)		||
			check(d1 - d2, d2)	||
			check(d1, d2 - d1)	||
			check(d2, d1 - d2)	||
			check(d2 - d1, d1)	||
			check(d2, d1))
			puts("yes");
		else puts("no");
	}
	return 0;
}