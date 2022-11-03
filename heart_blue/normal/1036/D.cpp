#pragma comment(linker, "/STACK:102400000,102400000") 
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
const int N = 5e5 + 10;
LL a[N];
LL b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int m;
	scanf("%d", &n);
	map<LL, int> mc;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
		mc[a[i]] = 1;
	}
	scanf("%d", &m);
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
		b[i] += b[i - 1];
		if (mc.count(b[i]))
			ans++;
	}
	if (b[m] != a[n]) ans = -1;
	printf("%d\n", ans);
	return 0;
}