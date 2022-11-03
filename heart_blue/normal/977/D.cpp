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
map<LL, LL> mc, to, deg;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		LL x;
		cin >> x;
		mc[x] = 1;
	}
	for (auto &p : mc)
	{
		auto x = p.first;
		if (x % 2 == 0 && mc.count(x / 2)) to[x / 2] = x, deg[x]++;
		if (x % 3 == 0 && mc.count(x / 3)) to[x] = x / 3, deg[x / 3]++;
	}
	LL s = 0;
	for (auto &p : mc)
	{
		if (!deg.count(p.first))
		{
			s = p.first;
			break;
		}
	}
	while (to.count(s))
	{
		printf("%lld ", s);
		s = to[s];
	}
	printf("%lld\n", s);
	return 0;
}