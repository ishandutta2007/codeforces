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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL a[N];
LL lsum[N];
LL rsum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, l, r, ql, qr;
	cin >> n >> l >> r >> ql >> qr;
	for (int i = 1; i <= n; i++) cin >> a[i];
	lsum[0] = rsum[n + 1] = 0;
	for (int i = 1; i <= n; i++) lsum[i] = a[i] + lsum[i - 1];
	for (int i = n; i >= 1; i--) rsum[i] = a[i] + rsum[i + 1];
	LL ans = INF*INF;
	for (int i = 0; i <= n; i++)
	{
		LL tmp = lsum[i] * l + rsum[i + 1] * r;
		if (i > n - i) tmp += (i - n + i - 1)*ql;
		if (i < n - i) tmp += (n - i - i - 1)*qr;
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}