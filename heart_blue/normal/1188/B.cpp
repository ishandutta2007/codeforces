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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, p, k;
	scanf("%d%d%d", &n, &p, &k);
	map<int, int> mc;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		int b = 1LL * a * a % p;
		b = 1LL * b * b % p;
		int x = (b - 1LL * a * k) % p;
		if (x < 0) x += p;
		ans += mc[x]++;
	}
	printf("%lld\n", ans);
	return 0;
}