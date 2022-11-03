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
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	int maxv = 0;
	map<pair<int, int>, int> mc;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (a[i] == 0)
		{
			if (x == 0) ans++;
			continue;
		}
		if (a[i] < 0) a[i] = -a[i], x = -x;
		int g = gcd(abs(a[i]), abs(x));
		maxv = max(maxv, ++mc[{a[i] / g, x / g}]);
	}
	cout << ans + maxv << endl;
	return 0;
}