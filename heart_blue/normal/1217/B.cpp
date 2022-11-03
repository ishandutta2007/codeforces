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
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, x;
		int ans = INF;
		scanf("%d%d", &n, &x);
		int dmax = 0;
		for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], dmax = max(dmax, a[i]);
		for(int i =1 ; i <= n; i++)
		{
			int d = a[i];
			int h = b[i];
			if (x <= d)
			{
				ans = 1;
				break;
			}
			if (d <= h) continue;
			ans = min(ans, (x - dmax + (d - h) - 1) / (d - h) + 1);
		}
		if (ans == INF) ans = -1;
		cout << ans << endl;
	}
	return 0;
}