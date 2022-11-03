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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL sum = 0;
	LL ans = 0;
	int n;
	scanf("%d", &n);
	LL r = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = n; i >= 1; i--)
	{
		sum -= a[i];
		int o = a[i] & 1;
		int x = a[i] - o;
		if ((o + sum) * 2 <= x + r)
		{
			ans = ans + (o + sum + x + r) / 3;
			break;
		}
		r += x;
		if (o && r > 1) r -= 2, ans++;
	}
	printf("%lld\n", ans);
	return 0;

}