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
const int N = 2e5 + 10;
char str[N];
LL sumx[N];
LL sumy[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL x1, y1;
	LL x2, y2;
	int n;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	x1 -= x2;
	y1 -= y2;
	cin >> n;
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
	{
		sumy[i] = sumy[i - 1];
		sumx[i] = sumx[i - 1];
		if (str[i] == 'U') sumy[i]++;
		if (str[i] == 'D') sumy[i]--;
		if (str[i] == 'R') sumx[i]++;
		if (str[i] == 'L') sumx[i]--;
	}
	LL ans = -1;
	LL l = 1, r = INF * INF;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		LL x = x1 + sumx[n] * (mid / n) + sumx[mid % n];
		LL y = y1 + sumy[n] * (mid / n) + sumy[mid % n];
		if (mid >= abs(x) + abs(y)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}