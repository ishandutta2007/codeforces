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
const int N = 1e5 + 10;
int a[N];
int lmin[N];
int rmin[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memcpy(lmin, a, sizeof(a));
	memcpy(rmin, a, sizeof(a));
	sort(a + 1, a + n + 1);
	if (k == 1)
	{
		cout << a[1] << endl;
		return 0;
	}
	if (k >= 3)
	{
		cout << a[n] << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++) lmin[i] = min(lmin[i], lmin[i - 1]);
	for (int i = n - 1; i > 0; i--) rmin[i] = min(rmin[i], rmin[i + 1]);
	int ans = -INF;
	for (int i = 1; i < n; i++) ans = max(ans, max(lmin[i], rmin[i + 1]));
	cout << ans << endl;
	return 0;
}