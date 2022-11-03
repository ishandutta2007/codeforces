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
const int N = 3e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, c;
		cin >> n >> c;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i < n; i++) cin >> b[i];
		LL ans = INF;
		LL rest = 0;
		LL cur = 0;
		for (int i = 1; i <= n; i++)
		{
			if (c <= rest)
			{
				ans = min(ans, cur);
				break;
			}
			else
			{
				ans = min(ans, cur + (c - rest + a[i] - 1) / a[i]);
			}
			if (i == n) break;
			LL o = 0;
			if (rest < b[i]) o = (b[i] - rest + a[i] - 1) / a[i];
			cur += o;
			rest += o * a[i];
			rest -= b[i];
			cur++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}