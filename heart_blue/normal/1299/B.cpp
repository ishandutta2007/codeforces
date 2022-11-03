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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<pair<LL, LL>, int> mp;
	int n;
	scanf("%d", &n);
	if (n & 1) puts("NO"), exit(0);
	LL sumx = 0, sumy = 0;
	for (int i = 1; i <= n; i++)
	{
		LL x, y;
		scanf("%lld%lld", &x, &y);
		sumx += x;
		sumy += y;
		mp[{x, y}] = 1;
	}
	if (sumx % (n / 2) || sumy % (n / 2)) puts("NO"), exit(0);
	sumx /= (n / 2);
	sumy /= (n / 2);
	for (auto& p : mp)
	{
		LL x, y;
		tie(x, y) = p.first;
		x = sumx - x;
		y = sumy - y;
		if (!mp.count(make_pair(x, y)))
			puts("NO"), exit(0);
	}
	puts("YES");
	return 0;
}