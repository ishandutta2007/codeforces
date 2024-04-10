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
int a[N], b[N], c[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	int sz1 = 0, sz2 = 0, sz3 = 0;
	for (int i = 1; i <= n; i++)
	{
		int x, o1, o2;
		scanf("%d%d%d", &x, &o1, &o2);
		if (o1 == o2 && o1 == 1) c[++sz3] = x;
		else if (o1 == 1) a[++sz1] = x;
		else if (o2 == 1) b[++sz2] = x;
	}
	sort(a + 1, a + sz1 + 1);
	sort(b + 1, b + sz2 + 1);
	sort(c + 1, c + sz3 + 1);
	for (int i = 2; i <= sz1; i++) a[i] += a[i - 1];
	for (int i = 2; i <= sz2; i++) b[i] += b[i - 1];
	for (int i = 2; i <= sz3; i++) c[i] += c[i - 1];
	if (min(sz1, sz2) + sz3 < k) puts("-1"), exit(0);
	int ans = 2 * INF;
	for (int i = 0; i <= min(k, sz3); i++)
	{
		if (i + sz2 < k) continue;
		if (i + sz1 < k) continue;
		ans = min(ans, c[i] + a[k - i] + b[k - i]);
	}
	printf("%d\n", ans);

	return 0;
}