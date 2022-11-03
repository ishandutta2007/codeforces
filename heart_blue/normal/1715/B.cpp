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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		LL b, s;
		scanf("%d%d%lld%lld", &n, &k, &b, &s);
		if (b * k > s || b * k + 1LL * n * (k - 1) < s)
		{
			puts("-1");
			continue;
		}
		vector<LL> ans(n, 0LL);
		ans[0] = k * b;
		LL rest = s - k * b;
		for (auto& x : ans)
		{
			LL o = min(rest, k - 1LL);
			x += o;
			rest -= o;
			printf("%lld ", x);
		}
		puts("");
	}
	return 0;
}