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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
tuple<int, int, int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, a, b;
	cin >> n >> a >> b;
	map<LL, int> mc;
	map<pair<LL, LL>, int> mp;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		LL x, vx, vy;
		cin >> x >> vx >> vy;
		ans += mc[vx*a - vy] - mp[{vx, vy}];
		mc[vx*a - vy]++;
		mp[{vx, vy}]++;
	}
	printf("%lld\n", ans*2);
	return 0;
}