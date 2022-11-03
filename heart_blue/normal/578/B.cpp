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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL a[N];
LL lsum[N];
LL rsum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, x;
	cin >> n >> k >> x;
	MEM(lsum, 0);
	MEM(rsum, 0);
	LL o = 1;
	while (k--) o *= x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) lsum[i] |= a[i] | lsum[i - 1];
	for (int i = n; i >= 1; i--) rsum[i] |= a[i] | rsum[i + 1];
	LL ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, lsum[i - 1] | rsum[i + 1] | a[i] * o);
	cout << ans << endl;
	return 0;
}