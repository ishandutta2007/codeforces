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
const int N = 3e5 + 10;
map<int, int> mc;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	LL sum = 0;
	long double ans = 0;
	for (int i = 0; i < n; i++)
	{
		LL x;
		scanf("%lld", &x);
		ans += i*x - sum;
		sum += x;
		mc[x]++;
		if (mc.count(x - 1)) ans -= mc[x - 1];
		if (mc.count(x + 1)) ans += mc[x + 1];
	}
	printf("%.0Lf\n", ans);
	return 0;
}