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
const int N = 2e5 + 10;
LL sum(LL n)
{
	return n * (n +1) / 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	LL minv = INF*INF;
	LL maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		LL tot = sum(i - 1) + sum(n - i);
		minv = min(minv, tot);
		maxv = max(maxv, tot);
	}
	LL ans = 0;
	LL tot = 0;
	while (m--)
	{
		int x, d;
		cin >> x >> d;
		tot += x;
		ans += max(d*minv, d*maxv);
	}
	printf("%.15f\n", 1.0*ans / n + tot);
	return 0;
}