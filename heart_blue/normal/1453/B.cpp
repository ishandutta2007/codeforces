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
int a[N];
int n;
int check(int l, int r)
{
	if (l < 1) return 0;
	if (r > n) return 0;
	return abs(a[l] - a[r]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		LL tot = 0;
		for (int i = 1; i <= n; i++) tot += check(i, i + 1);
		LL ans = tot;
		for (int i = 1; i <= n; i++)
		{
			ans = min(ans, tot - check(i - 1, i) - check(i, i + 1) + check(i - 1, i + 1));
		}
		printf("%lld\n", ans);
	}
	return 0;
}