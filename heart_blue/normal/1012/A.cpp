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
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i];
	sort(a + 1, a + 2 * n + 1);
	LL ans = 1LL * (a[n] - a[1])*(a[2 * n] - a[n + 1]);
	int l = n;
	int r = n + 1;
	while (r < 2 * n)
	{
		ans = min(ans, 1LL * (a[n * 2] - a[l])*(a[r] - a[1]));
		r++, l--;
	}
	for (int i = 2; i <= n; i++)
	{
		ans = min(ans, 1LL * (a[2 * n] - a[1])*(a[i + n - 1] - a[i]));
	}
	cout << ans << endl;

	return 0;
}