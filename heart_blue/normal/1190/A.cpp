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
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		LL o = (a[i] - 1 - (i - 1)) % k;
		LL cur = a[i] - o - 1;
		LL offset = 0;
		int j = i;
		while (j <= m)
		{
			if (a[j] > cur + k + offset) break;
			int key = j;
			for (int t = j; t <= m; t++)
			{
				if (a[t] > cur + k + offset)
				{
					break;
				}
				key = t;
			}
			offset += key - j + 1;
			j = key + 1;
			ans++;
		}
		i = j - 1;
	}
	cout << ans << endl;
	return 0;
}