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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
bool check(int n, int w)
{
	int tot = w;
	for (int i = 1; i <= n; i++)
	{
		tot += a[i];
		if (tot < 0) return false;
	}
	tot = 0;
	for (int i = 1; i <= n; i++)
	{
		tot += a[i];
		if (tot > w) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, w;
	cin >> n >> w;
	LL l = 0, r = w;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (!check(n, w))
	{
		puts("0");
		return 0;
	}
	LL lo = 0;
	while (l <= r)
	{
		LL mid = (r + l) >> 1;
		LL tot = mid;
		for (int i = 1; i <= n; i++)
		{
			tot += a[i];
			if (tot < 0) break;
		}
		if (tot < 0) l = mid + 1;
		else r = mid - 1, lo = mid;
	}
	LL hi = w;
	l = 0, r = w;
	while (l <= r)
	{
		LL mid = (r + l) >> 1;
		LL tot = mid;
		for (int i = 1; i <= n; i++)
		{
			tot += a[i];
			if (tot > w) break;
		}
		if (tot > w) r = mid - 1;
		else l = mid + 1, hi = mid;
	}
	cout << max(0LL, hi - lo + 1) << endl;
	return 0;
}