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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int cal(int x, int n, int r)
{
	int ans = x / n * r;
	x %= n;
	ans += max(0, x - r + 1);
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 0;
		for (int i = 1; i <= INF; i *= 2)
		{
			ans = max(ans, cal(r, i * 2, i) - cal(l - 1, i * 2, i));
		}
		printf("%d\n", r - l + 1 - ans);
	}
	return 0;
}