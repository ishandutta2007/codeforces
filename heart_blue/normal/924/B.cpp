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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	double ans = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int l = i + 2, r = n - 1;
		int key = -1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (a[mid] - a[i] <= m) key = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (key >= 0) ans = max(ans, 1.0*(a[key] - a[i + 1]) / (a[key] - a[i]));
	}
	printf("%.15f\n", ans);
	return 0;
}