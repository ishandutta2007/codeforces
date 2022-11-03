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
int a[N];
LL check(int l, int r)
{
	LL sum = 0;
	LL maxv = -INF;
	for (int i = l; i <= r; i++)
	{
		sum = max(1LL * a[i], a[i] + sum);
		maxv = max(maxv, sum);
	}
	return maxv;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		LL sum = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		if (sum > max(check(1, n - 1), check(2, n))) puts("YES");
		else puts("NO");
	}
	return 0;
}