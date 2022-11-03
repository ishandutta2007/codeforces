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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	map<int, int> mc;
	mc[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for (int j = 1; j <= k; j++)
		{
			if (!mc.count(a[i] * j)) mc[a[i] * j] = j;
			else mc[a[i] * j] = min(mc[a[i] * j], j);
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		int ans = k + 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				if (mc.count(x - a[i] * j)) 
					ans = min(ans, j + mc[x - a[i] * j]);
			}
		}
		if (ans == k + 1) ans = -1;
		cout << ans << endl;
	}
	return 0;
}