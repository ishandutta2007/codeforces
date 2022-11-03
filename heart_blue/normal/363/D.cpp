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
const int N = 1e5 + 10;
int b[N], p[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, a;
	cin >> n >> m >> a;
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < m; i++) cin >> p[i];
	sort(b, b + n);
	sort(p, p + m);
	int o = max(n - m, 0);
	n = min(n, m);
	for (int i = 0; i < n; i++) b[i] = b[i + o];
	int l = 0, r = n - 1;
	int key = n;
	LL cost = 0;
	LL ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		LL tot = 0;
		LL cost = 0;
		for (int i = mid; i < n; i++)
		{
			tot += max(0, p[i - mid] - b[i]);
			cost += p[i - mid];
		}
		if (tot > a) l = mid + 1;
		else r = mid - 1, key = mid, ans = cost-tot-min(cost-tot,a-tot);
	}
	if (key == n) puts("0 0");
	else printf("%d %lld\n", n-key, ans);
	return 0;
}