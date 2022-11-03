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
LL a[N];
LL b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL k, x;
	int n;
	cin >> n >> x >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && a[i] == a[i - 1])
		{
			b[i] = b[i - 1];
			ans += b[i];
			continue;
		}
		LL o = (a[i] - 1) / x * x - 1 + (k + 1) * x;
		b[i] = upper_bound(a + i, a + n, o) - upper_bound(a + i, a + n, o - x);
		ans += b[i];
	}
	cout << ans << endl;
	return 0;
}