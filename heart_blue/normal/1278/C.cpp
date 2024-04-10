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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= 2 * n; i++)
		{
			int x;
			cin >> x;
			a[i] = a[i - 1];
			if (x == 1) a[i]++;
			else a[i]--;
		}
		int tot = a[n * 2];
		map<int, int> mc;
		mc[0] = 0;
		int ans = 2 * n;
		if (a[n * 2] == 0) ans = 0;
		for (int i = 1; i <= 2 * n; i++)
		{
			if (i >= n && mc.count(a[i] - tot))
			{
				ans = min(ans, i - (int)mc[a[i] - tot]);
			}
			if (i <= n) mc[a[i]] = i;
		}
		cout << ans << endl;
	}
	return 0;
}