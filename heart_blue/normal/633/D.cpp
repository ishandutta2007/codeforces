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
const int N = 3e5 + 10;
int a[N];
map<pair<int, int>, int> mp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> mc;
	int ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], mc[a[i]]++;
	int zero = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0) zero++;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (a[i] == a[j] && a[i] == 0) continue;
			if (mp.count({ a[i],a[j] })) continue;
			mp[{a[i], a[j]}] = 1;
			int x = a[i], y = a[j];
			map<int, int> m;
			m[x]++;
			m[y]++;
			int cnt = 2;
			while (1)
			{
				int z = x + y;
				m[z]++;
				if (!mc.count(z) || m[z] > mc[z]) break;
				cnt++;
				x = y;
				y = z;
			}
			ans = max(ans, cnt);
		}
	}
	cout << max(ans, zero) << endl;

	return 0;
}