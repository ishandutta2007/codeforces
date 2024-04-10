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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		LL tot = 0;
		LL ans = 0;
		vector<int> v(n);
		for (auto& x : v)
		{
			scanf("%d", &x);
			tot += x;
		}
		LL sum = 0;
		sort(v.begin(), v.end());
		for (auto& x : v)
		{
			sum += x;
			ans = max(ans, abs(abs(sum) - abs(tot - sum)));
		}
		printf("%lld\n", ans);
	}
	return 0;
}