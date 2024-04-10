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
#include <valarray>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL h1, d1;
		LL h2, d2;
		scanf("%lld%lld%lld%lld", &h1, &d1, &h2, &d2);
		LL k, w, a;
		scanf("%lld%lld%lld", &k, &w, &a);
		int flag = 0;
		for (int i = 0; i <= k; i++)
		{
			LL h = i * a + h1, d = (k - i) * w + d1;
			LL cnt1 = (h + d2 - 1) / d2, cnt2 = (h2 + d - 1) / d;
			if (cnt2 <= cnt1)
				flag = 1;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}