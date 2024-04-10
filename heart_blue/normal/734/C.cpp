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
const int N = 2e5 + 10;
int a[N];
int b[N];
int c[N];
int d[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m, k;
	cin >> n >> m >> k;
	LL x, s;
	cin >> x >> s;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= k; i++) cin >> c[i];
	for (int i = 1; i <= k; i++) cin >> d[i];
	c[0] = d[0] = 0;
	b[0] = 0;
	a[0] = x;
	k++;
	m++;
	LL ans = x*n;
	for (int i = 0; i < m; i++)
	{
		if (b[i] > s) continue;
		LL t = a[i] * n;
		int o = upper_bound(d, d + k, s - b[i]) - d - 1;
		if (o != -1) ans = min(t - (LL)a[i] * c[o], ans);
	}
	cout << ans << endl;
	return 0;
}