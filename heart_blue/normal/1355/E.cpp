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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL h[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, r, m;
	scanf("%d%d%d%d", &n, &a, &r, &m);

	vector<LL> v;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &h[i]);
		v.push_back(h[i]);
	}
	sort(h + 1, h + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + h[i];
	}
	v.push_back(sum[n] / n);
	if (sum[n] % n) v.push_back(sum[n] / n + 1);
	LL ans = INF * INF;
	m = min(m, a + r);
	for (auto& x : v)
	{
		int j = upper_bound(h + 1, h + n + 1, x) - h;
		int i = j - 1;
		LL lsum = x * i - sum[i];
		LL rsum = sum[n] - sum[i] - (n - j + 1) * x;
		LL o = min(lsum, rsum);
		ans = min(ans, o * m + (lsum - o) * a + (rsum - o) * r);
	}
	printf("%lld\n", ans);


	return 0;
}