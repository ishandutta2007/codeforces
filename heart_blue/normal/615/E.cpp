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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int dx[] = { 1,-1,-2,-1,1,2 };
int dy[] = { 2,2,0,-2,-2,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	scanf("%lld", &n);
	LL l = 1, r = 1e10;
	LL key = 0;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		if (3 * mid + 2 <= n / mid) key = mid, l = mid + 1;
		else r = mid - 1;
	}
	LL x = key;
	LL y = -2 * key;
	// 3*i*(i+1)-i
	n -= 1LL * key * (3 * key + 2);
	LL rest = n;
	key++;
	LL a[] = { key,key - 1,key,key,key,key };
	for (int i = 0; i < 6; i++)
	{
		LL o = min(rest, a[i]);
		rest -= o;
		x += dx[i] * o;
		y += dy[i] * o;
	}
	printf("%lld %lld\n", x, y);
	return 0;
}