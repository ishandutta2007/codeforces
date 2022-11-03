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
const int N = 2e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> v1(n);
		for (auto& x : v1)
			scanf("%d", &x);
		sort(v1.begin(), v1.end());
		vector<int> v2(k);
		int cnt = 0;
		for (auto& x : v2)
		{
			scanf("%d", &x);
			if (x == 1) cnt++;
		}
		sort(v2.begin(), v2.end());
		LL ans = 0;
		while (k--)
		{
			ans += v1.back();
			if (cnt > 0) ans += v1.back(), cnt--;
			v1.pop_back();
		}
		for (auto x : v2)
		{
			if (x == 1) continue;
			x--;
			while (x > 1)
			{
				v1.pop_back();
				x--;
			}
			ans += v1.back();
			v1.pop_back();
		}
		printf("%lld\n", ans);
	}
	return 0;
}