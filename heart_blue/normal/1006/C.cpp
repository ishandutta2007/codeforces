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
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
LL a[N];
map<LL, int> mc;
void add(LL x)
{
	mc[x]++;
}
void del(LL x)
{
	mc[x]--;
	if (mc[x] == 0) mc.erase(x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
		mc[a[i]]++;
	}
	LL sum = 0;
	for (int i = n; i >= 0; i--)
	{
		sum += a[i] - a[i - 1];
		del(a[i]);
		if (mc.count(sum))
			ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}